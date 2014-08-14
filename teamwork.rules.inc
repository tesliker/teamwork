<?php
/*
* Implementation of hook_rules_action_info().
*/
function teamwork_rules_action_info() {
  $actions['teamwork_action_create_task'] = array(
    'label' => t('Add a task') ,
    'parameter' => array(
      'teamwork_person' => array(
        'description' => t("If you do not have select options available then Teamwork module hasn't been properly configured yet.") ,
 //       'description' =>  db_query('SELECT company_name FROM {teamwork_api} WHERE uid = :uid', array(':uid' => $user->uid))->fetchField(),
        'type' => 'text',
        'label' => t('Who is this assigned to?') ,
        'options list' => 'person_options',
        'restriction' => 'input',
      ) ,
      'teamwork_tasklist' => array(
        'type' => 'text',
        'label' => t('Which Task list?') ,
        'options list' => 'tasklist_options',
        'restriction' => 'input',
      ) ,
      'teamwork_date' => array(
        'type' => 'date',
        'label' => t('What is the Due Date') ,
        'description' => t("For today's date use the selector 'site:current-date', or you can switch to direct input mode to enter any date") ,
        'default mode' => 'selector',
      ) ,
      'teamwork_task' => array(
        'type' => 'text',
        'label' => t('What is the task?') ,
        'description' => t('You can use any number of replacement patterns for this.') ,
      ) ,
    ) ,
    'group' => t('Teamwork') ,
    'base' => 'teamwork_action_create_task',
    'callbacks' => array(
      'execute' => 'teamwork_action_create_task',
    ) ,
  );
  $actions['teamwork_action_update_status'] = array(
    'label' => t('Update Status') ,
    'parameter' => array(
      'teamwork_person_status' => array(
        'description' => t("If you do not have select options available then Teamwork module hasn't been properly configured yet.") ,
        'type' => 'text',
        'label' => t("Who's status is being updated?") ,
        'options list' => 'person_options',
        'restriction' => 'input',
      ) ,
      'teamwork_status' => array(
        'type' => 'text',
        'label' => t('What are you doing?') ,
        'description' => t('You can use any number of replacement patterns for this.') ,
      ) ,
    ) ,
    'group' => t('Teamwork') ,
    'base' => 'teamwork_action_update_status',
    'callbacks' => array(
      'execute' => 'teamwork_action_update_status',
    ) ,
  );
  return $actions;
}
/*
* Implementation of my tasklist options using a cURL to fetch from teamwork in the 'teamwork_tasklist' Array
*/
function tasklist_options() {
global $user;
    $company = db_query('SELECT company_name FROM {teamwork_api} WHERE uid = :uid', array(':uid' => $user->uid))->fetchField();
    $action = 'tasklists.json';
  function fetch_url($url) {
      global $user;
      $key = db_query('SELECT api_key FROM {teamwork_api} WHERE uid = :uid', array(':uid' => $user->uid))->fetchField();
      //$key = 'elvis437tide';
    $channel = curl_init();
    curl_setopt($channel, CURLOPT_URL, $url);
    curl_setopt($channel, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($channel, CURLOPT_HTTPHEADER, array(
      "Authorization: BASIC " . base64_encode($key . ":xxx")
    ));
    $feed_data = curl_exec($channel);
    curl_close($channel);
    return $feed_data;
  }
  $json_object = fetch_url("https://" . $company . ".teamwork.com/" . $action);
  $feed_array = json_decode($json_object, TRUE);
  $projects = array();
  foreach ($feed_array['todo-lists'] as $project) {
    $projects[] = array(
      $project['id'] => $project['name']
    );
  }
  return $projects;
}
/*
* Implementation of my person options using a cURL to fetch from teamwork in the 'teamwork_person' Array
*/
function person_options() {
    global $user;
    $company = db_query('SELECT company_name FROM {teamwork_api} WHERE uid = :uid', array(':uid' => $user->uid))->fetchField();
 // $action = "people.json";
  function fetch_url2($url) {
      global $user;
      $key = db_query('SELECT api_key FROM {teamwork_api} WHERE uid = :uid', array(':uid' => $user->uid))->fetchField();
    $channel = curl_init();
    curl_setopt($channel, CURLOPT_URL, $url);
    curl_setopt($channel, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($channel, CURLOPT_HTTPHEADER, array(
      "Authorization: BASIC " . base64_encode($key . ":xxx")
    ));
    $feed_data = curl_exec($channel);
    curl_close($channel);
    return $feed_data;
  }
  $json_object = fetch_url2("https://" . $company . ".teamwork.com/people.json");
  $feed_array = json_decode($json_object, TRUE);
  $projects = array();
  foreach ($feed_array['people'] as $project) {
    $projects[] = array(
      $project['id'] => $project['user-name']
    );
  }
  return $projects;
}
/*
* Implementation of my function create a task with variables from rules using cURL
*/
function teamwork_action_create_task($teamwork_person, $teamwork_tasklist, $teamwork_date, $teamwork_task) {
    global $user;
  $key = db_query('SELECT api_key FROM {teamwork_api} WHERE uid = :uid', array(':uid' => $user->uid))->fetchField();
  $company = db_query('SELECT company_name FROM {teamwork_api} WHERE uid = :uid', array(':uid' => $user->uid))->fetchField();
  $task_list_people_id = $teamwork_person;
  $task_list_id = $teamwork_tasklist;
  $task_date = date('Ymd', $teamwork_date);
  $task_name = $teamwork_task;
  $arr = array(
    'todo-item' => array(
      'content' => $task_name,
      'responsible-party-id' => $task_list_people_id,
      'due-date' => $task_date
    )
  );
  $json = json_encode($arr);
  $channel = curl_init();
  curl_setopt($channel, CURLOPT_URL, "https://{$company}.teamwork.com/todo_lists/{$task_list_id}/todo_items.json");
  curl_setopt($channel, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($channel, CURLOPT_POST, 1);
  curl_setopt($channel, CURLOPT_POSTFIELDS, $json);
  curl_setopt($channel, CURLOPT_HTTPHEADER, array(
    "Authorization: BASIC " . base64_encode($key . ":xxx") ,
    "Content-type: application/json"
  ));
  curl_exec($channel);
  curl_close($channel);
}

function teamwork_action_update_status($teamwork_person_status, $teamwork_status) {
    global $user;
  $key = db_query('SELECT api_key FROM {teamwork_api} WHERE uid = :uid', array(':uid' => $user->uid))->fetchField();
  $company = db_query('SELECT company_name FROM {teamwork_api} WHERE uid = :uid', array(':uid' => $user->uid))->fetchField();
  $arr = array(
    'userStatus' => array(
      'id' => $teamwork_person_status,
      'status' => $teamwork_status
    )
  );
   drupal_set_message($teamwork_person_status. $teamwork_status);
  $json = json_encode($arr);
  $channel = curl_init();
  curl_setopt($channel, CURLOPT_URL, "https://{$company}.teamwork.com/people/{$teamwork_person_status}/status.json");
  curl_setopt($channel, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($channel, CURLOPT_POST, 1);
  curl_setopt($channel, CURLOPT_POSTFIELDS, $json);
  curl_setopt($channel, CURLOPT_HTTPHEADER, array(
    "Authorization: BASIC " . base64_encode($key . ":xxx") ,
    "Content-type: application/json"
  ));
  curl_exec($channel);
  curl_close($channel);
}
