<?php
/*
Refresh database with teamwork
*/
function teamwork_people_refresh($action) {
  global $user;
  $key = db_query('SELECT api_key FROM {teamwork_api} WHERE uid = :uid', array(':uid' => $user->uid))->fetchField();
  $company = db_query('SELECT company_name FROM {teamwork_api} WHERE uid = :uid', array(':uid' => $user->uid))->fetchField();
  $result = drupal_http_request('https://'.$key.'@'.$company.'.teamwork.com/'.$action."'");
 // $decode_feed = json_decode($result);
  $feed_array = json_decode($result->data, TRUE);

    foreach ($feed_array['people'] as $project) {
  $insert_people = db_merge('teamwork_people');
  $insert_people
   ->key(array('uid' => $user->uid, 'id' => $project['id']))
   ->fields(array(
     'uid' => $user->uid,
	 'first_name' => $project['first-name'],
	 'id' => $project['id'],
	 'last_name' => $project['last-name'],
	 'email' => $project['email-address'],
	 'user_name' => $project['user-name'],
	 'avatar_url' => $project['avatar-url'],
   ))
   ->execute();
   }
}
/*
Refresh database with teamwork
*/

function teamwork_tasks_refresh($action) {
  global $user;
  $key = db_query('SELECT api_key FROM {teamwork_api} WHERE uid = :uid', array(':uid' => $user->uid))->fetchField();
  $company = db_query('SELECT company_name FROM {teamwork_api} WHERE uid = :uid', array(':uid' => $user->uid))->fetchField();
  $result = drupal_http_request('https://'.$key.'@'.$company.'.teamwork.com/'.$action."'");
 // $decode_feed = json_decode($result);
  $feed_array = json_decode($result->data, TRUE);

  foreach ($feed_array['todo-items'] as $project) {
  $insert_tasks = db_merge('teamwork_tasks');
  $insert_tasks
   ->key(array('uid' => $user->uid, 'id' => $project['id']))
   ->fields(array(
     'uid' => $user->uid,
	 'id' => $project['id'],
	 'comments_count' => $project['comments-count'],
	 'description' => $project['description'],
	 'content' => $project['content'],
	 'private' => ($project['private'] == TRUE) ? 1 : 0,
	 //'order' => $project['order'],
	 'project_id' => $project['project-id'],
     'project_name' => $project['project-name'],
	 'todo_list_id' => $project['todo_list_id'],
	 'todo_list_name' => $project['todo-list-name'],
	 'status' => $project['status'],
	 'company_name' => $project['company-name'],
	 'company_id' => $project['company-id'],
	 'creator_id' => $project['creator-id'],
	 'creator_firstname' => $project['creator-firstname'],
	 'creator_lastname' => $project['creator-lastname'],
	 'completed' => ($project['completed'] == TRUE) ? 1 : 0,
	 'start_date' => $project['start-date'],
	 'due_date' => $project['due-date'],
	 'created_on' => $project['created-on'],
	 'priority' => $project['priority'],
	 'progress' => $project['progress'],
	 'timeIsLogged' => ($project['timeIsLogged'] == TRUE) ? 1 : 0,
	 'attachments_count' => $project['attachments-count'],
	 //'responsible_party_id' => $project['responsible-party-id'],
	 'responsible_party_firstname' => $project['responsible-party-firstname'],
	 'responsible_party_lastname' => $project['responsible-party-lastname'],

   ))
   ->execute();
   }
} 


function teamwork_tasklists_refresh($action) {
  global $user;
  $key = db_query('SELECT api_key FROM {teamwork_api} WHERE uid = :uid', array(':uid' => $user->uid))->fetchField();
  $company = db_query('SELECT company_name FROM {teamwork_api} WHERE uid = :uid', array(':uid' => $user->uid))->fetchField();
  $result = drupal_http_request('https://'.$key.'@'.$company.'.teamwork.com/'.$action."'");
 // $decode_feed = json_decode($result);
  $feed_array = json_decode($result->data, TRUE);
    foreach ($feed_array['todo-lists'] as $project) {
  $insert_people = db_merge('teamwork_tasklists');
  $insert_people
   ->key(array('uid' => $user->uid, 'id' => $project['id']))
   ->fields(array(
     'uid' => $user->uid,
	 'project_id' => $project['project-id'],
	 'name' => $project['name'],
	 'description' => $project['description'],
	 'milestone_id' => $project['milestone-id'],
	 'uncompleted_count' => $project['uncompleted-count'],
	 'complete' => ($project['complete'] == TRUE) ? 1 : 0,
     'private' => ($project['private'] == TRUE) ? 1 : 0,
	 'overdue_count' => $project['overdue-count'],
	 'project_name' => $project['project-name'],
	 'pinned' => ($project['pinned'] == TRUE) ? 1 : 0,
	 'tracked' => ($project['tracked'] == TRUE) ? 1 : 0,
	 'id' => $project['id'],
	 'position' => $project['position'],
     'completed_count' => $project['completed-count'],
   ))
   ->execute();
   }
}


	