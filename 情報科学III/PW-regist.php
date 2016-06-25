<html>
<head>
	<meta http-equiv="CONTENT-TYPE"	CONTENT="text/html;CHARSET=UTF-8">
	<title>Sample for Password</title>
</head>
<body>
<?php
$name = $_POST["name"];
$password = $_POST["password"];
if($name == "" || $password == ""){
	die("名前とパスワードの両方を入力してください。");
}

require('PW-dbaccess.php');

//利用者名が既に登録されているかチェック
$sql = "SELECT * FROM users WHERE name = '$name'";
$result = mysql_query($sql);
if($result == FALSE){
	echo mysql_error();
	die("問い合わせに失敗しました");
}
else{
	$num = mysql_num_rows($result);
	if($num != 0){
		echo "利用者 $name はすでに登録されているため、登録できません。";
		exit;
	}
}

//	データの登録
$sql = "INSERT INTO users (name, password) VALUES ('$name',PASSWORD('$password'))";
$result = mysql_query($sql);
if($result == FALSE){
	echo mysql_error();
	die("登録に失敗しました。");
}
else{
	echo "利用者 $name の登録に成功しました。";
}
?>
<A Href="main.html">戻る</A>
</body>
</html>	