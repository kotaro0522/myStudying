<!doctype html>
<HTML lang="ja">
	<HEAD>
		<meta charset="utf-8">
		<TITLE>体重</TITLE>
	</HEAD>
	<BODY>
		<?php
			echo 'あなたの体重は' . htmlspecialchars($_POST["weight"]*1000) . 'gです。';
		?>
	</BODY>
</HTML>