<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
        "http://www.w3.org/TR/html4/loose.dtd"> 
   <?php
//z因为一开始在win下开发，坑了
    header("Content-type:text/html;charset=gb2312");

    //导入文件
    require("blackmusicplayer/demo/fwcs/get_ip.php");

    ?>  




<html>
<head>
    <meta name="author" content="lxp">
    <meta name="keywords" content="LITTLE MUSIC PLAYER,动漫,游戏,BGM,轻音乐,主题曲,op,ed,插曲,好听的">
    <title>LITTLE MUSIC PLAYER --个人音乐网站</title>
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
<p>声明：本网页仅供本人学习与娱乐</p>
<p>源码下载地址： Download Here</p></a>
   <div id="fangwencishu">访问总量为：
      <?php
         echo $count;
      ?>
</div> 
</body>



</html>
