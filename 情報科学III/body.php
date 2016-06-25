<!doctype html>
<HTML lang="ja">
	<HEAD>
		<meta charset="utf-8">
		<TITLE>体格</TITLE>
	</HEAD>
	<BODY>
		<?php
			echo 'あなたの身長は' . htmlspecialchars($_POST["tall"]/100) . 'mです。<BR>';
			echo 'あなたの体重は' . htmlspecialchars($_POST["weight"]*1000) . 'gです。';
		?>
	</BODY>
</HTML>