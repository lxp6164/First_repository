
<?php
    

    $file_path = "blackmusicplayer/demo/fwcs/counter.dat";
    $count = intval(file_get_contents($file_path));

    //获取ip
    $ip = $_SERVER["REMOTE_ADDR"];
    
    if(getenv("HTTP_X_FORWARDED_FOR"))
        $ip = getenv("HTTP_X_FORWARDED_FOR");
    

    //echo $ip;
    //echo "<br/>";
    $int_ip = ip2long($ip);
    //echo $int_ip; 
    

    $time1 = date('Y-m-d H:i:s');
   // echo "<br/>";
    //echo $time1;
    $time_now = strtotime($time1);
   // echo "<br/>";		
 //   echo $time_now;



/////////////////////////////////////////////////////////////////////////////////
                                            //password
   
    $mysqli = new mysqli("localhost","root","*********","views_ip");
    if ($mysqli->connect_errno) {
       printf("Connect failed: %s\n", $mysqli->connect_error);
       exit();
    }

   // echo "<br/>";
   // echo "connect ok";

/////////////////////////////////////////////////////////////////////////////////////////////

    $sql_exit = "select count(ip) from id_ip where ip = '$int_ip'";
    if ($result = $mysqli->query($sql_exit)) 
    {
   // echo "<br/>";
   // printf("Select returned %d rows.\n", $result->num_rows);
    $res_exit = mysqli_fetch_array($result);
    $result->close();
    }
  //  echo "<br/>";
    $cnt_exit = $res_exit[0];
  //  echo $cnt_exit;
 //   echo "<br/>";

///////////////////////////////////////////////////////////////////////////////////
    
   if($cnt_exit == 0)
   {
      $count++;
     // echo $count;
      file_put_contents($file_path,$count);
      
     /////////////////////////////////////////////////////////////
      $sql1 = "select count(id) from id_ip";
      if ($result = $mysqli->query($sql1)) 
      {

     // echo "<br/>";
     //printf("Select returned %d rows.\n", $result->num_rows);
      $res = mysqli_fetch_array($result);
      $result->close();
      }

      $cnt = $res[0] + 1;
   //   echo "<br/>";
   //   echo $cnt;
   //   echo "<br/>";
   //   echo "select ok";




     /////////////////////////////////////////////////////////////////

      $sql2 = "insert into id_ip values('$cnt','$int_ip','$time_now')";
      $mysqli->query($sql2);
   //   echo "<br/>";
//
  //    if($mysqli->query($sql2) ===true)
  //    {
  //         echo "yyyyy";
  //   }
   //  else { echo "nnnn";}
 

 }

   


  //  echo "<br/>";
   // echo "insert ok";


    mysqli_close($mysqli); 



///////////////////////////////////////////////////////////////////////////////////////////////////
///////////     统计所有ip     ///////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

    
    $mysqli_all = new mysqli("localhost","root","************","all_views_ip");
    if ($mysqli_all->connect_errno) {
       printf("Connect failed: %s\n", $mysqli_all->connect_error);
       exit();
    }

   // echo "<br/>";
   // echo "connect ok";
//////////////////////////////////////////////////////////////////////////////////////////////

    $sql_exit_all = "select count(ip) from id_ip where ip = '$int_ip'";
    if ($result = $mysqli_all->query($sql_exit_all)) 
    {
   // echo "<br/>";
   // printf("Select returned %d rows.\n", $result->num_rows);
    $res_exit_all = mysqli_fetch_array($result);
    $result->close();
    }
  //  echo "<br/>";
    $cnt_exit_all = $res_exit_all[0];
  //  echo $cnt_exit;
 //   echo "<br/>";


////////////////////////////////////////////////////////////////////////////////////////////    
   if($cnt_exit_all == 0)
   {   

      $sql1_all = "select count(id) from id_ip";
      if ($result = $mysqli_all->query($sql1_all)) 
      {
      // echo "<br/>";
      //printf("Select returned %d rows.\n", $result->num_rows);
        $res_all = mysqli_fetch_array($result);
        $result->close();
      }

 //   echo "<br/>";
    $cnt_all = $res_all[0] + 1;
  //  echo $cnt_all;
  //  echo "<br/>";
  //  echo "select ok";



      $sql2_all = "insert into id_ip values('$cnt_all','$int_ip','$time_now')";
      $mysqli_all->query($sql2_all);    
//   echo "<br/>";
//
    //  if($mysqli_all->query($sql2_all) ===true)  echo "yyyyy";
       
   //      else  echo "nnnn";




   }

   


  //  echo "<br/>";
   // echo "insert ok";


    mysqli_close($mysqli_all);     









/*
CREATE EVENT ip_event
ON SCHEDULE EVERY 1 MINUTE STARTS '2017-03-21 02:00:00'
DO
delete from id_ip 
where ptime < date_sub(curdate(),interval 1 minute);
*/



/*
    session_start();
    $file_path = "blackmusicplayer/demo/fwcs/counter.dat";
    $count = intval(file_get_contents($file_path));
    if(!isset($_SESSION['view']))
    {

         $count++;
        // echo $count;
        if(is_writable($file_path)) //居然是权限问题
        {  $_SESSION['view'] = true;
           file_put_contents($file_path,$count);
          // echo "文件写入成功!";
        }
         else  {echo "访问人数统计失败!";}
    }

*/
?>


















<!--

#  count(*)  当前总人数
#  int_ip        
#  时间

-->
