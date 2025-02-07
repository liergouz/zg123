
#include <npc.h>
#include <ansi.h>

inherit OFFICER;
string cWord;
int iPic;
// 函数：获取人物造型
int get_char_picid() 
{ 
	int z;
	if ( !iPic )
	{
		z = get_z(this_object());
		if ( z == 283 || z == 20 || z == 371 || z == 10 )
			iPic = 2006;
		else
			iPic = 2005;		
	}
	return iPic; } 

// 函数：构造处理
void create()
{
        set_name("");
        setup();
	set("mpLegend",([0:({31}),]));
}

void do_look( object who )
{ 
	int z;
	object me=this_object();
	if ( !cWord )
	{
		z = get_z(who);
		switch(z)
		{
		case 162:
			cWord = "注意，这条路将会踏入"HIR"沼泽边缘"NOR"，里面是"HIR"30"NOR"级的怪物，请三思！！";
			break;
		case 165:
			cWord = "警告！这里是通向"HIR"沼泽边缘"NOR"的道路，都是"HIR"30"NOR"级的怪物！！";
			break;
		case 283:
			cWord = "仙家重地，非"HIR"95级"NOR"的闲人勿进！！";
			break;
		case 20:
			cWord = HIR"弯道"NOR"危险，"HIR"70"NOR"级以下闲人勿进！！";
			break;
		case 324:
			cWord = HIR"弯道"NOR"危险，"HIR"70"NOR"级以下闲人勿进！！";
			break;
		case 42:
			cWord = "此乃"HIR"将军古墓"NOR"，内有"HIR"85"NOR"级的怪物镇守，盗墓者请三思！！";
			break;
		case 211:
			cWord = "官府告示：\n　　"HIR"灵谷洞"NOR"内有"HIR"75"NOR"级的妖魔，非关系人等不得入内！！";
			break;
		case 371:
			cWord = "小心王八。";
			break;
		case 10:
			cWord = "府上告示：\n　　此乃"HIR"诛仙阵"NOR"，阵中封印了无数千年妖魔，非能力高强者勿进。";
			break;		
		case 132:
			cWord = "官府告示：\n　　"HIR"太行山洞"NOR"已被封锁，闲杂人等不得入内，否则后果自负。";
			break;	
		case 231:
			cWord = "进入坑内的人注意：脚下躺着的就是你们的榜样。";
			break;	
		case 171:
			cWord = "赠君一言：\n　　人为财死，鸟为食亡。";
			break;	
		case 111:
			cWord = "官府告示：\n　　"HIR"泰山山洞"NOR"已被封锁，闲杂人等不得入内，否则后果自负。";
			break;	
		default:
			cWord = HIR"熊出没"NOR"注意";
			break;
		}
	}
	send_user(who,"%c%c%w%s",':',3,0,cWord);
}