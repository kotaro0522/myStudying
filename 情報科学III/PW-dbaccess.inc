<?php
$mysql_host = "localhost";
$mysql_user	= "ds113193t";
$mysql_password	= "19930522";
$my_database = "ds113193t_testauth";

$link = mysql_connect($mysql_host,$mysql_user,$mysql_password);

if(!$link){ die('接続できませんでした：'.mysql_error());}

mysql_query("SET CHARACTER SET utf8",$link);
mysql_select_db($my_database,$link);
?>
