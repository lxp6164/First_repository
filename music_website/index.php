<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
        "http://www.w3.org/TR/html4/loose.dtd"> 
   <?php
//z��Ϊһ��ʼ��win�¿���������
    header("Content-type:text/html;charset=gb2312");

    //�����ļ�
    require("blackmusicplayer/demo/fwcs/get_ip.php");

    ?>  




<html>
<head>
    <meta name="author" content="lxp">
    <meta name="keywords" content="LITTLE MUSIC PLAYER,����,��Ϸ,BGM,������,������,op,ed,����,������">
    <title>LITTLE MUSIC PLAYER --����������վ</title>
    <link rel="shortcut icon" type="image/x-icon" href="blackmusicplayer/demo/images/lxp_logo.ico" media="screen" /> 
    <link rel="stylesheet" type="text/css" href="blackmusicplayer/plugin/css/style.css">
    <link rel="stylesheet" type="text/css" href="blackmusicplayer/demo/css/demo.css">
    <script type="text/javascript" src="blackmusicplayer/demo/js/jquery-1.6.1.min.js"></script>
    <script type="text/javascript" src="blackmusicplayer/demo/js/bgchange.js"></script>
    <script type="text/javascript" src="blackmusicplayer/plugin/jquery-jplayer/jquery.jplayer.js"></script>
    <script type="text/javascript" src="blackmusicplayer/plugin/ttw-music-player.js"></script>
    <script type="text/javascript" src="blackmusicplayer/demo/js/myplaylist.js"></script>

    <script type="text/javascript">
        $(document).ready(function(){
            var description = 'HOPE YOU WOULD LOVE THESE. ';

            $('body').ttwMusicPlayer(myPlaylist, {
                autoPlay:false, 
                description:description,
                jPlayer:{
                    swfPath:'blackmusicplayer/plugin/jquery-jplayer' //You need to override the default swf path any time the directory structure changes
                }
            });
        });
    </script>

</head>


<body>

<div id="title"></div>

<a href="http://www.codebasehero.com/download?file=music-player" id="download" target="_blank">
<p>����������ҳ��������ѧϰ������</p>
<p>Դ�����ص�ַ�� Download Here</p></a>
   <div id="fangwencishu">��������Ϊ��
      <?php
         echo $count;
      ?>
</div> 
</body>



</html>
