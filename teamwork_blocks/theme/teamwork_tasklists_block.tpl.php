<?php

$result = db_query('SELECT * FROM {teamwork_tasklists} WHERE uid = :uid', array(':uid' => $user->uid))->fetchAll(PDO::FETCH_ASSOC);
$miniresult = db_query('SELECT * FROM {teamwork_tasks} WHERE uid = :uid', array(':uid' => $user->uid) )->fetchAll(PDO::FETCH_ASSOC);	
drupal_add_library('system', 'drupal.collapse');
foreach($result as $key=>$value)
{
?>

<fieldset class="collapsible collapsed">
	<legend><span class="fieldset-legend"><?php print $value['name'] ?></span></legend>
	<div class="fieldset-wrapper">
	<ul>
<?php

foreach($miniresult as $keys=>$values)
{ if ($values['todo_list_name'] == $value['name']) {?>

<li><?php print $values['content'] ?></li>
<?php }
}
?>
</ul>	</div>
</fieldset> 
<?php
} 
?>