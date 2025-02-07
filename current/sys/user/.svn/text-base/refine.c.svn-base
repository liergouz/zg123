
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <npc.h>
#include <time.h>

mapping level_message = ([
	50:	({ "长白山一带或封妖镜镜像", "50", "54", }), // ～
	55:	({ "燕长城或封妖镜镜像", "55", "59", }),
	60:	({ "赵长城或封妖镜镜像", "60", "65", }),
	65:	({ "秦长城或封妖镜镜像", "65", "69", }),
	70:	({ "弯道或封妖镜镜像", "70", "75", }),
	75:	({ "灵谷洞或封妖镜镜像", "75", "86", }),
	80:	({ "万人坑或封妖镜镜像", "80", "88", }),
	85:	({ "将军古墓或封妖镜镜像", "85", "93", }),
	90:	({ "困魔阵或封妖镜镜像", "90", "97", }),
	95:	({ "紫云洞一带或封妖镜镜像", "95", "100", }),
	100:	({ "九曲桥或封妖镜镜像", "100", "108", }),
	105:	({ "天门阵或封妖镜镜像", "105", "112", }),
	110:	({ "诛仙阵", "110", "116", }),
	115:	({ "诛仙阵", "110", "116", }),
	]);


// 函数：生成二进制码
void SAVE_BINARY() { }

void do_welcome(object me, object who, string arg)
{
	int type = to_int(arg);
	string result, *name;
	int iTime, day, p, level, i, size;
	mixed *mxTime;
	object item;
	level = me->get_level();
	if (MAIN_D->get_host_type()==6012)
	{
		result = sprintf("%s:\n    目前收妖任务尚未开放。\n", who->get_name());
		result += ESC"离开";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (level<50)
	{
		result = sprintf("%s:\n    以你现在的等级还不足以利用收妖壶，等你的等级到达50级之后你再来找我吧。\n", who->get_name());
		result += ESC"离开";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (level>120) 
	{
		result = sprintf("%s:\n    你现在的能力太高了。\n", who->get_name());
		result += ESC"离开";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}	
	if (me->get_city_name()!=who->get_city_name())
	{
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), sprintf("%s:\n    你我素无往来，这个任务之说无从谈起。\n", who->get_name()));
		return;
	}	
	if (me->get_save_2("refine.status")==1)
	{
		result = sprintf("%s:\n    你怎么还在这里？赶快去把那些危害广大黎民百姓的妖魔鬼怪的灵魂收进收妖壶里面去吧\n", who->get_name());
		result += ESC"离开";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	iTime = time();
	mxTime = localtime(iTime);
	day = mxTime[TIME_YDAY];	
	if (me->get_save_2("refine.status")==2&&me->get_save_2("refine.day")==day)
	{
		result = sprintf("%s:\n    这位侠士真是热心，但是现在我们的祭师炼化出来的收妖壶数量不够，如果你还想为广大黎民百姓除掉这些妖魔的话，等明天我们的祭师炼出了新的收妖壶之后，你再来领一个吧！\n", who->get_name());
		result += ESC"离开\n";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if( sizeof_inventory(me, 1, MAX_CARRY) >= MAX_CARRY )
	{
		result = sprintf("%s:\n    我看你全身都好像放满了东西的样子，你最好还是先把你身上没用的东西清理一下吧！\n", who->get_name());
		result += ESC"离开\n";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;		
	}		
	switch(type)
	{
	case 1000:
		result = sprintf("%s:\n    自从长平之战后，天下到处都是妖怪横行，百姓深受其害。有见及此，大王命我们寻觅了一位祭师为我们炼化了一些收妖壶，只要拿着这个壶把那些妖魔鬼怪杀掉，就可以把这些为祸人间的妖魔的灵魂收进收妖壶里面。如果你愿意去替我国广大黎民除魔斩妖的话，我可以给你一个收妖壶，你去杀掉450个跟你实力相当的妖怪，然后就可以把那些就灵魂收进壶里面了。\n", who->get_name());
		result += sprintf(ESC"接受\ntalk %x# welcome.1001\n", getoid(who));
		result += ESC"拒绝\n";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 1001:		
		item = new ("/item/01/0100");
		if (!item) return;
                p =item->move(me, -1);
		item->add_to_user(p);  	
		level = (level/5)*5;
		if (level>110) level = 110;
		name = level_message[level];
		result = sprintf("%s:\n    一个收妖壶可以收进450个妖魔的灵魂，以你现在的实力，你可以去"HIR"%s收%s～%s级的妖怪"NOR"的灵魂，当收集的灵魂满了以后，"HIR"右键点击收妖壶"NOR"，收妖壶就会连同里面的妖魔的灵魂被净化掉，你也会因为拯救黎民而得到上天的眷顾。\n", who->get_name(), name[0], name[1], name[2]);		
		result += ESC"离开\n";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		me->delete_save_2("refine");
		me->set_save_2("refine.status", 1);
		me->set_save_2("refine.level", me->get_level());
		me->set_save_2("refine.level1", to_int(name[1]));
		me->set_save_2("refine.level2", to_int(name[2]));
		send_user( me, "%c%c%c%w%s", 0x51, 1, 1, TID_REFINE, "收妖任务" ); 
		send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_REFINE, 1, "收妖壶任务" ); 
		send_user( me, "%c%s", '!', "你获得收妖壶");
		break;	
	}
}

string send_task_intro(object me)
{
	int level, i, size, exp;
	string result, *name, result2;
	if (me->get_save_2("refine.status")!=1) return "";
	level = me->get_save_2("refine.level");
	exp = "/sys/npc/energy"->get_exp_bonus(level);
	exp = exp*450/2;
	level = (level/5)*5;
	if (level<50) return "";
	if (level>110) level = 110;
	name = level_message[level];	
	result = sprintf(BLK"任务目的：\n"BLK"    把%s～%s级妖怪的灵魂一共450个收进收妖壶。\n"BLK"    灵魂收取量：%d/450。\n"BLK"任务描述：\n"BLK"    自从长平之战后，天下到处都是妖怪横行，百姓深受其害。有见及此，大王找了一个祭师打造了一批收妖壶，只要拿着这个壶把那些妖魔鬼怪杀掉，就可以把这些为祸人间的妖魔的灵魂收进收妖壶里面，这样，那些妖魔就不可以再为祸人间了。我的目的，是要去%s杀掉%s级的妖怪一共450个，然后就可以把那些就灵魂收进壶里面了。再把我这收满妖怪灵魂的收妖壶净化。\n"BLK"奖励：%d点经验\n",
	                        name[1], name[2], me->get_save_2("refine.count"), name[0], name[1], exp);	                
	return result;	                        
}

void task_giveup(object player )
{
	int time;
	object item;
	send_user( player, "%c%c%c%w%w%s", 0x51, 1, 2, TID_REFINE, 1, "" );
	send_user( player, "%c%c%c%w%s", 0x51, 1, 1, TID_REFINE, "" );
	player->delete_save_2("refine");
	// 删除收妖壶
	item = present("收妖壶", player, 1, MAX_CARRY*4);
	if (item)
	{
		item->remove_from_user();
	        destruct(item);	
	}	       
}