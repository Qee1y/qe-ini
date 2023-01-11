# qe-ini文件解析器

## 知识点
   ​ 面向对象设计
   ​ 函数重载
   ​ 运算符重载
   ​ 函数模板
   ​ 标准模板库
## 介绍  
   ### 一.什么是Ini
   ​ ini文件是Initialization File的缩写，即初始化文件，通常存放的是一个程序的初始化信息，是Windows的系统配置文件所采用的存储格式，统管windows的各项配置。ini文件的后缀名不一定是.ini，也可以是.cfg、.conf或者是.tx*。
  
   ### 二.ini文件格式&语法规范
    ​ ini文件由若干个节（section）组成，每个section由若干键（Key）组成，每个Key可以赋相应的值。读写ini文件实际上就是读写某个的section中相应的Key的值，而这只要借助几个函数即可完成。

   ### ***参数***（Parameter）：
    ​ ini文件包含的最基本元素是参数，参数包含参数名（name）和参数值（value），格式如下：name=value

   ### ***节（section）***：
    ​ 所有的参数都是以节为单位结合在一起。节名称独占一行，在节声明后的所有的参数都属于该节。节没有结束标识符，一个section的开始就是上一个section的结束。格式如下：[section]
## ini示例: sercofing.ini
    Properties
          1 [server]
          2 ip = 127.0.0.1
          3 port = 25565
          4 OnlineMode = false
          5 PvP = false
          6 CopyToClipboard = false
    
   

