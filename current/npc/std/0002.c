#include <npc.h>
#include <ansi.h>
#include <time.h>

inherit OFFICER;

mapping maps = ([
	101:	([ "name" : 	"楚方城１",
		   "locate" :	({ 061,208,133, }),
		]),		   
	102:	([ "name" : 	"楚方城２",
		   "locate" :	({ 062,43,40, }),
		]),		   
	103:	([ "name" : 	"楚方城３",
		   "locate" :	({ 063,196,151, }),
		]),		   
	104:	([ "name" : 	"上庸关",
		   "locate" :	({ 284,252,198, }),
		]),		   
	105:	([ "name" : 	"华山",
		   "locate" :	({ 283,208,28, }),
		]),		   
	106:	([ "name" : 	"桃花源",
		   "locate" :	({ 282,185,127, }),
		]),		   
	107:	([ "name" : 	"朝阳峰",
		   "locate" :	({ 281,29,150, }),
		]),		   

	201:	([ "name" : 	"首阳山",
		   "locate" :	({ 081,244,154, }),
		]),		   
	202:	([ "name" : 	"翠华山",
		   "locate" :	({ 082,200,80, }),
		]),		   
	203:	([ "name" : 	"函谷关",
		   "locate" :	({ 251,227,34, }),
		]),		   

	301:	([ "name" : 	"无定河１",
		   "locate" :	({ 042,337,218, }),
		]),		   
	302:	([ "name" : 	"无定河２",
		   "locate" :	({ 043,192,169, }),
		]),		   
	303:	([ "name" : 	"无定河畔",
		   "locate" :	({ 041,89,128, }),
		]),		   
	304:	([ "name" : 	"襄陵",
		   "locate" :	({ 021,176,54, }),
		]),		   
	305:	([ "name" : 	"马陵道",
		   "locate" :	({ 141,136,67, }),
		]),		   
	306:	([ "name" : 	"白马庄",
		   "locate" :	({ 142,100,56, }),
		]),		   
	307:	([ "name" : 	"马踏湖",
		   "locate" :	({ 211,159,141, }),
		]),		   

	401:	([ "name" : 	"虎牢关",
		   "locate" :	({ 089,85,59 }),
		]),		   
	402:	([ "name" : 	"萁关",
		   "locate" :	({ 181,226,48, }),
		]),		   
	403:	([ "name" : 	"巨鹿",
		   "locate" :	({ 131,64,63, }),
		]),		   
	404:	([ "name" : 	"涿鹿",
		   "locate" :	({ 271,199,183, }),
		]),		   
	405:	([ "name" : 	"易水",
		   "locate" :	({ 272,113,180, }),
		]),		   
	406:	([ "name" : 	"桂陵",
		   "locate" :	({ 242,133,40, }),
		]),		   
	407:	([ "name" : 	"牧野",
		   "locate" :	({ 241,138,43, }),
		]),		   
	408:	([ "name" : 	"太行山",
		   "locate" :	({ 132,83,35, }),
		]),		   
	409:	([ "name" : 	"晋阳",
		   "locate" :	({ 182,134,32, }),
		]),		   
	410:	([ "name" : 	"平原",
		   "locate" :	({ 243,120,51, }),
		]),		   
	411:	([ "name" : 	"雁门关",
		   "locate" :	({ 155,131,44, }),
		]),		   
	412:	([ "name" : 	"长平",
		   "locate" :	({ 231,157,158, }),
		]),
		
	501:	([ "name" : 	"沼泽边缘",
		   "locate" :	({ 163,81,109, }),
		]),	
	502:	([ "name" : 	"沼泽地带",
		   "locate" :	({ 164,76,102, }),
		]),
	503:	([ "name" : 	"大别山脚",
		   "locate" :	({ 261,101,42, }),
		]),
	504:	([ "name" : 	"大别山",
		   "locate" :	({ 262,91,35, }),
		]),
	505:	([ "name" : 	"巫山",
		   "locate" :	({ 263,53,46, }),
		]),
	506:	([ "name" : 	"鄱阳湖",
		   "locate" :	({ 264,48,117, }),
		]),
	507:	([ "name" : 	"赤壁",
		   "locate" :	({ 265,79,47, }),
		]),
	508:	([ "name" : 	"太湖",
		   "locate" :	({ 266,81,75, }),
		]),
	509:	([ "name" : 	"泰山山脚",
		   "locate" :	({ 112,149,178, }),
		]),
	510:	([ "name" : 	"泰山",
		   "locate" :	({ 111,136,180, }),
		]),		
			
	601:	([ "name" : 	"东海渔村",
		   "locate" :	({ 011,51,43, }),	
		]),		   
	602:	([ "name" : 	"东海岸",
		   "locate" :	({ 012,108,52, }),
		]),		   
	603:	([ "name" : 	"海滨１",
		   "locate" :	({ 013,51,121, }),
		]),		   
	604:	([ "name" : 	"海滨２",
		   "locate" :	({ 014,70,77, }),
		]),		   
	605:	([ "name" : 	"东海岛",
		   "locate" :	({ 015,130,29, }),
		]),		   
	606:	([ "name" : 	"郑国渠１",
		   "locate" :	({ 151,76,24, }),
		]),		   
	607:	([ "name" : 	"郑国渠２",
		   "locate" :	({ 152,47,40, }),
		]),		   
	608:	([ "name" : 	"郑国渠３",
		   "locate" :	({ 153,31,48, }),	
		]),		   	   		   		   		   		   		   		   															
]);




// 函数：获取人物造型
int get_char_picid() { return 6010; }
void do_welcome(string arg);

// 函数：构造处理
void create()
{
        set_name("新手特派传送员");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
        setup();
}

void do_look(object who)
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, "");
}

void do_welcome( string arg )
{
        object who = this_object();
        __FILE__ ->do_welcome2(who, arg);
}

void do_welcome2( object who, string arg )
{
	int flag,id,i,size,p, x, y, z, *locate;
       	object me, robber;
       	string result;
       	mapping temp;
        me = this_player();
        flag = to_int(arg);
        me->set_time( "talk",  0);
        id = getoid(who);
        if (arg=="")
        {
        	if (me->get_level()>50)
        		result = sprintf("%s：\n    你已经超过50级了吧。现在还想利用这个提供给新手的传送方式的话，每次传送都要付我500金哦。\n", who->get_name() );
        	else
        		result = sprintf("%s：\n    哎呀，看你是新来的嘛，认识我吗？我就是大名鼎鼎的新手特派传送员了！各大门派掌门为了门下新弟子的发展，委托我在这看有没有像你这样新来的，好送你去合适等级区域练级。只限10级到50级的新人哦，把握机会吧！\n", who->get_name() );
        	result += sprintf(ESC "传送到10－14级练级地图\ntalk %x# welcome.100\n", id );
        	result += sprintf(ESC "传送到15－19级练级地图\ntalk %x# welcome.200\n", id );
        	result += sprintf(ESC "传送到20－24级练级地图\ntalk %x# welcome.300\n", id );
        	result += sprintf(ESC "传送到25－30级练级地图\ntalk %x# welcome.400\n", id );
        	result += sprintf(ESC "传送到31－40级练级地图\ntalk %x# welcome.500\n", id );
        	result += sprintf(ESC "传送到41－50级练级地图\ntalk %x# welcome.600\n", id );
        	result += ESC"离开\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	return ;
        }
        if (me->get_level()<10)
        {
        	result = sprintf("%s：\n    你好像还很弱哦，就在新手村附近完成一些任务，达到10级再来找我吧。\n", who->get_name() );
        	result += ESC"离开\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	return;
        }
	if( me->get_save_2("51cuanye.time")  )
	{
        	result = sprintf("%s：\n    你领取了接受极限穿越任务，我就暂不接待了。\n", who->get_name() );
        	result += ESC"离开\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	return;
	}
        if( present("钱票", me, 1, MAX_CARRY) )
        {
        	result = sprintf("%s：\n    你身上有钱票，我就暂不接待了。\n", who->get_name() );
        	result += ESC"离开\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	return;        	
        }
        if( present("贵重物品", me, 1, MAX_CARRY) )
        {
        	result = sprintf("%s：\n    你身上有贵重物品，我就暂不接待了。\n", who->get_name() );
        	result += ESC"离开\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	return;   
        }
        if( objectp( robber = me->get_quest("escort.robber#") ) && robber->is_escort_robber() )    // 寻找蒙面人
        {
        	result = sprintf("%s：\n    你附近有蒙面人，我就暂不接待了。\n", who->get_name() );
        	result += ESC"离开\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	return;         	
        }        
        switch(flag)
        {
        case 100:
        	result = sprintf("%s：\n    你要去10级以上15级以下的练级地图吗？来，选择吧！按Alt+M可以查看这些地图具体的怪物种类哦。\n", who->get_name() );
        	for (i=0;i<7;i++)
        		result += sprintf(ESC "%s\ntalk %x# welcome.%d\n", maps[101+i]["name"], id, 101+i );
        	result += ESC"离开\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	break;
        case 200:
        	result = sprintf("%s：\n    你要去15级以上20级以下的练级地图吗？来，选择吧！按Alt+M可以查看这些地图具体的怪物种类哦。\n", who->get_name() );
        	for (i=0;i<3;i++)
        		result += sprintf(ESC "%s\ntalk %x# welcome.%d\n", maps[201+i]["name"], id, 201+i );
        	result += ESC"离开\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	break;        	
        case 300:
        	result = sprintf("%s：\n    你要去20级以上25级以下的练级地图吗？来，选择吧！按Alt+M可以查看这些地图具体的怪物种类哦。\n", who->get_name() );
        	for (i=0;i<7;i++)
        		result += sprintf(ESC "%s\ntalk %x# welcome.%d\n", maps[301+i]["name"], id, 301+i );
        	result += ESC"离开\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	break;           
        case 400:
        	result = sprintf("%s：\n    你要去25级以上30级以下的练级地图吗？来，选择吧！按Alt+M可以查看这些地图具体的怪物种类哦。\n", who->get_name() );
        	for (i=0;i<12;i++)
        		result += sprintf(ESC "%s\ntalk %x# welcome.%d\n", maps[401+i]["name"], id, 401+i );
        	result += ESC"离开\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	break;     
        case 500:
        	result = sprintf("%s：\n    你要去31级以上40级以下的练级地图吗？来，选择吧！按Alt+M可以查看这些地图具体的怪物种类哦。\n", who->get_name() );
        	for (i=0;i<10;i++)
        		result += sprintf(ESC "%s\ntalk %x# welcome.%d\n", maps[501+i]["name"], id, 501+i );
        	result += ESC"离开\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	break;          
        case 600:
        	result = sprintf("%s：\n    你要去41级以上50级以下的练级地图吗？来，选择吧！按Alt+M可以查看这些地图具体的怪物种类哦。\n", who->get_name() );
        	for (i=0;i<8;i++)
        		result += sprintf(ESC "%s\ntalk %x# welcome.%d\n", maps[601+i]["name"], id, 601+i );
        	result += ESC"离开\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	break;           		
        default:     	        	
        	temp = 	maps[flag];
        	if (!temp) return;
        	if (temp["name"]==0) return;
        	locate = temp["locate"];
        	if (sizeof(locate)!=3) return;
        	if (me->get_level()>50)
        	{
        		if (me->get_cash()<500)
        		{
        			result = sprintf("%s：\n    大侠，最近手头紧么？\n", who->get_name() );
		        	result += ESC"离开\nCLOSE";
		        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return ;        			
        		}
        		me->add_cash(-500);
        	}
        	z = locate[0], x = locate[1], y = locate[2];
        	if( p = get_valid_xy(z, x, y, IS_CHAR_BLOCK) )
        	{
	                x = p / 1000;  y = p % 1000;	
	                me->add_to_scene( z, x, y, 3 );        		
        	}
        	break;
        }
}
