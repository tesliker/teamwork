<?php
$items = $variables['items'];

$people = $items['people'];

$result = db_query('SELECT * FROM {teamwork_people} WHERE uid = :uid', array(':uid' => $user->uid))->fetchAll(PDO::FETCH_ASSOC);
$items = array();
$items['people'] = array('#markup' => $result);

foreach($result as $key=>$value)
{
?>

<div style="width: 100%;" class="clearfix">
	<div style="width: 30%;float: left;">
	<img style="max-width: 50%;" src="<?php print $value['avatar_url']; ?>" />
	</div>
	<div style="width: 70%;float: left;">
	<p><?php print $value['first_name']." ".$value['last_name']; ?></p>
	</div>
</div> 
<?php
}
?>