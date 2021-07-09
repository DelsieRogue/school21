<?php

$cfg['blowfish_secret'] = '212121212121212121212121212121212121212';

$i = 0;

$i++;

$cfg['Servers'][$i]['auth_type'] = 'cookie';

$cfg['Servers'][$i]['host'] = 'mysql-svc';
$cfg['Servers'][$i]['compress'] = false;

$cfg['Servers'][$i]['port'] = '3306';
$cfg['Servers'][$i]['controluser'] = 'root';
$cfg['Servers'][$i]['controlpass'] = 'pass';

$cfg['UploadDir'] = '';
$cfg['SaveDir'] = '';
