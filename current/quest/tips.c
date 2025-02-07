
#include <ansi.h>
#include <task.h>

// 数组：标准提示信息 -- [随意]
mapping TipsTable = ([

        "1" :   "等级提升后人物的能力会相应增强，同时会获得" HIY "四个属性点" NOR "的奖励。打开人物属性界面（快捷键 ALT+W），可以将奖励的点数自由分配到 "HIY "五项基本属性" NOR "中。\n",
        "2" :   "恭喜您顺利提升到十级！建议您马上拜访" HIY "新手村的门派向导" NOR "，他能将您送到七大门派。只要拜入七大门派之一，您的武功就会更上一层台阶。" HIY "门派向导" NOR "驻留在新手村东面的出口处，不要迟疑了，快去找他吧！\n",
        "3" :   "消灭怪物除了能获得一定的经验和物品奖励外，还能获得一种称为“" HIY "潜能" NOR "”的奖励。" HIY "潜能" NOR "是作为往后技能修炼时的一种消耗，当技能的等级越高时，所消耗的" HIY "潜能" NOR "也就越多。\n",
        "4" :   "您现在拣到的物品称为" HIY "使命物品" NOR "，通常在新手村、荒郊和野外附近都能找到它们。收集这些物品，将它们交给新手村的" HIY "卫队长" NOR "，便可以获得丰厚的奖励回报。\n",
        "5" :   "通过“Alt＋2”快捷组合键功能你便可以坐下。坐下之后能加快你气血与法力值的恢复速度。\n",
        "6" :	"按着" HIY "“Shift＋鼠标右键”" NOR "点击聊天信息中的玩家名字，便可以对该玩家发送悄悄话或者发出邀请组队的信息。\n",
        "7" :	"利用快捷键Alt＋ T点击自己组成一支队伍，此时再利用该功能点击其他玩家便可以邀请别人加入你的队伍了。同样，右键点击其他玩家的小头像也能弹出组队信息的相关操作。\n",
        "8" :	"在新手村、荒郊与野外一带，每相隔30分钟便会出现一批" HIY "“使命人物”" NOR "分布在这些场景中。快利用基础技能中的“查看使命人物”功能查看这些" HIY "“使命人物”" NOR "的位置，并找上志同道合的好朋友，组成一支队伍去挑战这些“使命人物”吧！\n",
        "9" :	"在游戏中遇到不懂的问题吗？还是找不到某一个NPC？快快打开好友界面，请"HIY "万事通" NOR"解答你的疑难问题吧。\n",
        "10":	"恭喜你已经越过新手的阶段了，是不是正在为金钱的事情而烦恼呢？听说周国的王捕头处能接到一份赚钱的好差事，何不去看看～\n",
        "11":	"听说新手村的卫队长处有不少好差事，既能赚钱又能锻炼自己，何不去看看～\n",
        "12":	"恭喜您到达了30级，快快找周国的神仙爷爷吧，听说老爷爷正在举行一个"HIR"‘VIP试用包’"NOR"大赠送的活动。VIP包内藏神奇功能，可使你体验更多战国精彩！只要成为了VIP用户，您将会得到许多意想不到的优惠服务。",
        "13":	"以你现在的实力，完全可以胜任成为别人的老师了。快去拜访一下周国的孔夫子，那位大师会教您如何成为一名称职的老师。\n",

]);

mapping mpScene = ([

	001 : 0,
	002 : 0,
	003 : 0,
	004 : 0,
	005 : 0,
	006 : 0,
	007 : 0,
	008 : 0,
	009 : 0,
	161 : 5,
	162 : 5,
	061 : 10,
	062 : 10,
	063 : 10,
	281 : 10,
	282 : 10,
	283 : 10,
	284 : 10,
	081 : 15,
	082 : 15,
	251 : 15,
	021 : 20,
	041 : 20,
	042 : 20,
	043 : 20,
	141 : 20,
	142 : 20,
	211 : 20,
	089 : 25,
	131 : 25,
	132 : 25,
	155 : 25,
	181 : 25,
	182 : 25,
	231 : 25,
	241 : 25,
	242 : 25,
	243 : 25,
	271 : 25,
	272 : 25,
	164 : 30,
	261 : 30,
	262 : 30,
	263 : 30,
	264 : 30,
	111 : 35,
	112 : 35,
	265 : 35,
	266 : 35,
	011 : 40,
	012 : 40,
	013 : 40,
	014 : 40,
	015 : 40,
	151 : 45,
	152 : 45,
	153 : 45,
	501 : 45,
	502 : 45,
	503 : 45,
	171 : 50,
	172 : 50,
	173 : 50,
	174 : 50,
	528 : 50,
	529 : 50,
	530 : 50,
	071 : 55,
	072 : 55,
	073 : 55,
	512 : 55,
	513 : 55,
	031 : 60,
	032 : 60,
	033 : 60,
	510 : 60,
	511 : 60,
	051 : 65,
	052 : 65,
	053 : 65,
	524 : 65,
	525 : 65,
	526 : 65,
	527 : 65,
	321 : 70,
	322 : 70,
	323 : 70,
	516 : 70,
	517 : 70,
	311 : 75,
	312 : 75,
	313 : 75,
	514 : 75,
	515 : 75,
	311 : 75,
	312 : 75,
	313 : 75,
	331 : 80,
	332 : 80,
	333 : 80,
	334 : 80,
	335 : 80,
	504 : 80,
	505 : 80,
	341 : 85,
	342 : 85,
	343 : 85,
	344 : 85,
	345 : 85,
	508 : 85,
	509 : 85,
	291 : 90,
	292 : 90,
	293 : 90,
	506 : 90,
	507 : 90,
	381 : 95,
	383 : 95,
	385 : 95,
	520 : 95,
	522 : 95,
	372 : 100,
	373 : 100,
	374 : 100,
	521 : 100,
	523 : 100,
	091 : 105,
	092 : 105,
	093 : 105,
	531 : 105,
	532 : 105,
	391 : 110,
	392 : 110,
	393 : 110,
	518 : 110,
	519 : 110,

	]);

//
mapping mpGradeScene = ([


		]);

// 数组：新手提示信息 -- [随意]
mapping NewbieTipsTable = ([

        "1" :   "          欢迎光临《战国Ⅱ Online》。\n看到前方那位" HIY "美丽的小仙女" NOR "了吗？试试用" HIY "鼠标右键" NOR "点向那位" HIY "小仙女" NOR "，您的人物便会朝着小仙女的方向移动。",


        "2" :   "当鼠标指针移到 NPC 身上时，指针会变成一个" HIY "对话标志" NOR "，此时只要点击一下" HIY "鼠标左键" NOR "，就能同 NPC 进行交谈了。\n",                

]);

// 数组：场景公用提示 -- [200～255]
mapping CommonTipsTable = ([

        "255" : "在田地里可以采集到各种各样的药草，根据所处地域的不同，可以采集到的" HIY "药草" NOR "也不尽相同。通过使用生活技能" HIY "采集" NOR "，便可以进行" HIY "药草" NOR "的采集工作。\n",

]);

// 数组：地图场景提示 -- [地图号][001～199]
mapping MapTipsTable = ([

        "1001" : "欢迎来到新手村，这里是新手们聚集的地方，也是无数勇士成长的故乡。拜访这里的村民，仔细聆听他们的谈话，您会了解到这个世界更多的事情。\n",

        "1002" : "顺着青石小径一直往前走，就能到达新手村了。小仙女所说的神仙爷爷就在村的入口等着你呢。\n",

//        "1003" : "请将" HIY "百合仙子的信件" NOR "交给" HIY "神仙爷爷" NOR "。这样你便可以完成百合仙子的委托了。\n",

        "1004" : "看到部分 NPC 头上浮动的“对话”标识吗？这表示该 NPC 有一项任务要交予您完成，当您接受任务后这个标识会变成灰色，直到您完成委托任务后该标识才会消失。\n",

        "1005" : "新手村的南面是野外，东面通向洞庭湖，而北面则是一处荒郊。这几个地方都是新手的活动区域，相当适合于新手们打怪练级。\n",

        "1006" : "点击组队按钮（快捷键 T），鼠标指针会转变为一面小旗，用小旗点击自己即可组成一支" HIY "队伍" NOR "，如果点击其他玩家则是申请加入别人的队伍。\n",

        "1007" : "只有组队才能消灭村外的" HIY "使命人物" NOR "，消灭这些" HIY "使命人物" NOR "后能获得比一般的怪物更多的奖励经验。\n",

        "1008" : "酒店老板那里不但出售食物和酒，而且还能找到酒食技能所需要的各种烹饪材料。\n",

        "1009" : "除了新手村，游戏中还有齐、韩、赵、魏、秦、楚、燕、周八大城市，通过驿站老板可以使您穿梭于这些城市之间。\n",

        "1010" : "您可以在武器店买到刀、枪、剑、棍、拳套、暗器等不同种类的武器。同时您也可以将自己身上没用的物品卖给武器店老板。\n",

        "1011" : "修理店老板可以帮助您将损坏的武器装备修复，只不过要花费不少金钱。\n",

        "1012" : "防具店可以买到各种各样防具用品。同时您也可以将自己身上没有的物品卖给防具店老板。\n",

        "1013" : "当铺老板可以帮您将物品，或者金钱暂时保管起来。当您需要时，随时可以通过当铺老板将其取出。另外，在门派学习技能时，如果您身上携带现金不足，不足的部分将会从您在当铺中的存款中直接扣除，直至存款不足以学习技能为止。\n",

        "1014" : "您可以在杂货店买到各种必须的用品，比如回城符、飞行符等等。您也可以将自己身上没用的物品卖给杂货店老板以换取一些金钱。\n",

        "1015" : "你可以在药店买到各种恢复类的药品。你也可以将自己身上没用的物品卖给药店的老板以换取一些金钱。\n",

        "80001" : "这里是周国的摆摊区，如果您要将自己身上的道具物品贩卖给其它有兴趣的玩家，请站在这个区域内，通过基础技能中的“摆摊”指令，摆个独具特色的小摊挡吧！\n",

]);

// 函数：显示提示信息(标准)
void send_tips( object me, string id ) 
{ 
        if( !id || !TipsTable[id] ) return;
        send_user( me, "%c%s", ';', TipsTable[id] );
}

// 函数：显示提示信息(新手)
void send_newbie_tips( object me, string id ) 
{ 
        if( !id || !NewbieTipsTable[id] ) return;
        send_user( me, "%c%s", ';', NewbieTipsTable[id] );
}

// 函数：显示提示信息(场景公用)
void send_common_tips( object me, string id ) 
{ 
        if( !id || !CommonTipsTable[id] ) return;
        send_user( me, "%c%s", ';', CommonTipsTable[id] );
}

// 函数：显示提示信息(地图)
void send_map_tips( object me, string id ) 
{ 
        int z, p;
	int status;
        z = get_z(me);  p = to_int(id);
	id = sprintf("%d%03d", z, p);
	status = me->get_save("tipsstatus");
        switch(id)
        {
        case "80001":
        	"/quest/help"->send_help_tips(me, 23);
        	break;
        case "80002":
        	"/quest/help"->send_help_tips(me, 32);
        	break;
        case "80003":
        	"/quest/help"->send_help_tips(me, 18);
        	break;       
        case "1001":
        	"/quest/help"->send_help_tips(me, 50);       
        	break; 	 	        	
        case "1002":
        	"/quest/help"->send_help_tips(me, 37);
        	"/quest/help"->send_help_tips(me, 48);
        	break;        
        case "1004":
        	"/quest/help"->send_help_tips(me, 38);
        	break;    
        case "1005":
        	"/quest/help"->send_help_tips(me, 39);
        	break;    
        case "1006":
        	"/quest/help"->send_help_tips(me, 40);
        	break;            	        	        	
        }	
        switch( z )
        {
       case 1 : 
       		if (status & (1<<p)) return;
       		status = status | (1<<p);
       		me->set_save("tipsstatus", status);
		break;
        }
        

        if( !id || !MapTipsTable[id] ) return;
        


        send_user( me, "%c%s", ';', MapTipsTable[id] );
}

void create()
{
	int i,size,*nTmp,p,g;
	
	nTmp = keys(mpScene);
	for(i=0,size=sizeof(nTmp);i<size;i++)
	{
		p = nTmp[i];
		g = mpScene[p];
		if ( !arrayp(mpGradeScene[g]) )
			mpGradeScene[g] = ({ p });
		else
			mpGradeScene[g] += ({ p });
	}	
}

void enter_scene_tip(object who,object map)
{
	int level,level1,z,*nTmp,i,size;
	string cName,cTmp;
	object map1;
	z = map->get_id();
	if ( undefinedp(level1=mpScene[z]) )
	{
		send_user(who,"%c%c%s",0xA5,1,map->get_name()); 
		return ;	
	}
	level = who->get_level();
	cName = map->get_name();
	level = level/5*5;
	
	if ( level1 >= level + 10 )
		cName = cName + "|" + sprintf(HIR"%d级区域，慎入！",level1);
	else if ( level1 >= level + 5 )
		cName = cName + "|" + sprintf(HIY"%d级区域！",level1);
	else
		cName = cName + "|" + sprintf("%d级区域",level1);
	send_user(who,"%c%c%s",0xA5,1,cName); 
	
	if ( level1 > level )
	{
		cTmp = "";
		nTmp = mpGradeScene[level];
		if (sizeof(nTmp)==0) return;
		nTmp = sort_array(nTmp,1);
		for(i=0,size=sizeof(nTmp);i<size;i++)
		{
			if ( !objectp(map1 = get_map_object(nTmp[i])) )
				continue;
			if ( sizeof(cTmp) )
				cTmp += "、";
			cTmp += map1->get_name();
		}
		if ( sizeof(cTmp) )
			send_user(who,"%c%s",';',"为了您的安全着想，建议您去适合您现在等级的"+HIR+cTmp+NOR+"一带练级。");
	}
//	send_user( who, "%c%s", '!', map->get_name() );
}
