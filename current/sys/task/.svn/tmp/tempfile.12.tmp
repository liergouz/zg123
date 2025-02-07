
#include <ansi.h>
#include <task.h>
#include <npc.h>
#include <item.h>
#include <cmd.h>
#include <time.h>
#include <equip.h>
// 函数：生成二进制码
void SAVE_BINARY() { }

// 流浪商人的坐标
int SellerLocate = 0;

string *mastername = ({"周王", "齐王", "楚王", "秦王", "燕王", "赵王", "魏王", "韩王", "蜀山真人", "鬼谷子", "广成子", "茅真人", "唐老爷子", "大将军", "无名老人", });
string *locatename = ({ "周国", "齐国", "楚国", "秦国", "燕国", "赵国", "魏国", "韩国", "蜀山", "云梦泽", "昆仑山", "茅山", "唐门", "禁卫军", "桃花源", });
string *giftname = ({ "0104", "0109", "0111", "0121", "0131", "0141", "0151", "0161", "0202", "0401", "0402", "0403", "0211", "0212", "0316", "0317", "0319", "0221", "0231", "0222", "0325", "0329", "0241", "0251", "0242", "0348", "0349", "0261", "0363", "0364", "0365", "0368", "0271", "0413", "0414", "0417", "0418", "0421", "0422", "0423", "0424", "0425", "0281", "0501", "0511", "0531", "0591", });
string *cityname = ({ "齐国", "楚国", "秦国", "燕国", "赵国", "魏国", "韩国", });
string *schoolname = ({"桃花源", "蜀山", "禁卫军", "唐门", "茅山", "昆仑山", "云梦泽", });
mapping mpSkill = ([
        	"桃花源": 	({ 0211, 0212, 0316, 0317, 0319, }),
        	"蜀山":		({ 0221, 0231, 0222, 0325, 0329, }),
        	"禁卫军":	({ 0241, 0251, 0242, 0348, 0349, }),
        	"唐门":		({ 0261, 0363, 0364, 0365, 0368, }),
        	"茅山":		({ 0271, 0413, 0414, 0417, 0418, }),
        	"昆仑山":	({ 0421, 0422, 0423, 0424, 0425, }),
        	"云梦泽":	({ 0281, 0501, 0511, 0531, 0591, }),
	]);
mapping FamilyBook =
        ([
        	"桃花源": 	({ "0211", "0212", "0316", "0317", "0319", }),
        	"蜀山":		({ "0221", "0231", "0222", "0325", "0329", }),
        	"禁卫军":	({ "0241", "0251", "0242", "0348", "0349", }),
        	"唐门":		({ "0261", "0363", "0364", "0365", "0368", }),
        	"茅山":		({ "0271", "0413", "0414", "0417", "0418", }),
        	"昆仑山":	({ "0421", "0422", "0423", "0424", "0425", }),
        	"云梦泽":	({ "0281", "0501", "0511", "0531", "0591", }),
	]);
string *TaskName = ({"抓怪","历练","游历","采购","收集","拜访","寻踪任务","协助治安","巡山","门派切磋","筹集资金","追杀叛徒","追捕刺客"});
void check_random_bonus(object player);
int do_look2(object player, object master );
void task_bonus(object player, object master);
int get_city_number(string city);
void task_finish9(object player, object master);
void give_five_bonus(object who);
void clear_task(object player,int iCancel);
void send_task_desc(object who,int iClear);
void clear_task_desc(object who, int type);
void send_task_list(object who, int type);
void extra_skill_bonus(object who);
void init_npc(object npc);
void check_date(object player)
{
	mixed *mixTime;
	mixTime = localtime(time());
	if (mixTime[TIME_YDAY]!=player->get_save_2("mastertask.day"))
	{
		player->set_save_2("mastertask.day", mixTime[TIME_YDAY]);
	        player->set_save_2("mastertask.count", 0);
	        player->set_save_2("mastertask.fivebonus", 0);
	}
}
void do_look(object player, object master )
{
	string name1, name2, result = "",cTmp;
	int id, status, time, level, date, exp, pot, order1, order2;
        object npc;

        name1 = player->get_fam_name();
        name2 = master->get_fam_name();

        // 拜访任务
        if ( __FILE__->do_look2(player, master)==1 )
        	return ;
        if( name1 == "" || name1 != name2 || player->get_fam_master()!=master->get_name() )
        {
                TASK_APPRENTICE_D->do_look(player, master);
                return;
        }
	id = getoid(master);
	order1 = player->get_fam_order();
	order2 = master->get_fam_order();

	if (player->get_save_2("master_hide"))
	{
		result = sprintf( "%s：\n    本门武艺博大精深，具有化腐朽为神奇，夺天地造化之功。小徒你平常需要多努力钻研才好。不知今日找为师有何事干？\n"ESC "学习技能\ntalk %x# skills\n", master->get_name(), id );
                if (order1==order2 && order2!=1) result += sprintf(ESC"挑战\ntalk %x# apprentice.1\n", id);
                result += sprintf(ESC"还有哪里可以买到本门派的武器？\ntalk %x# apprentice.11\n",getoid(master));
                result += sprintf(ESC"购买本门派装备\nlist %x#\n",getoid(master));
                //增加强化技能学习选项。
//                if (!player->get_save("kjh_enhance_sk") )
                {
//                	if (player->get_level()>=60
//                	&& (present("天恩令",player,1,MAX_CARRY*4) ) )
                	{
	                	result += sprintf(ESC"申请学习强化门派技能\ntalk %x# apprentice.15\n",getoid(master));
                	}
                }
                result += ESC"向师傅请安\nCLOSE";
	        send_user( player, "%c%s", ':', result );
	        return ;
	}

	if ((status=player->get_save_2("mastertask.type"))>0 )
	{
		if ( status > sizeof(TaskName) )
			return ;
		if ( status == 4 || status == 5 || status == 6 || status == 8 || status == 11 || status == 12 )
			result = sprintf( "%s：\n    本门武艺博大精深，具有化腐朽为神奇，夺天地造化之功。小徒你平常需要多努力钻研才好。不知今日找为师有何事干？\n"ESC "学习技能\ntalk %x# skills\n"
	        		, master->get_name(), id );
		else
			result = sprintf( "%s：\n    本门武艺博大精深，具有化腐朽为神奇，夺天地造化之功。小徒你平常需要多努力钻研才好。不知今日找为师有何事干？\n"ESC "学习技能\ntalk %x# skills\n"
	        		ESC "%s\ntalk %x# task_info\n", master->get_name(), id,TaskName[status-1],id );
                if (order1==order2 && order2!=1) result += sprintf(ESC"挑战\ntalk %x# apprentice.1\n", id);
                result += sprintf(ESC"还有哪里可以买到本门派的武器？\ntalk %x# apprentice.11\n",getoid(master));
                if (order2==4) result += sprintf(ESC"购买本门派装备\nlist %x#\n",getoid(master));
                //增加强化技能学习选项。
//                if (!player->get_save("kjh_enhance_sk") )
                {
//                	if (player->get_level()>=60
//                	&& (present("天恩令",player,1,MAX_CARRY*4) ) )
                	{
	                	result += sprintf(ESC"申请学习强化门派技能\ntalk %x# apprentice.15\n",getoid(master));
                	}
                }
                result += ESC"向师傅请安\nCLOSE";
	        send_user( player, "%c%s", ':', result );
	        return ;
	}

	check_date(player);
	result = sprintf( "    本门武艺博大精深，具有化腐朽为神奇，夺天地造化之功。小徒你平常需要多努力钻研才好。不知今日找为师有何事干？\n"
	        ESC "学习技能\ntalk %x# skills\n"ESC "领取任务\ntalk %x# quest\n", id, id );
        if (order1==order2 && order2!=1) result += sprintf(ESC"挑战\ntalk %x# apprentice.1\n", id);
	result += sprintf(ESC"还有哪里可以买到本门派的武器？\ntalk %x# apprentice.11\n",getoid(master));
	result += sprintf(ESC"购买本门初级装备\nlist %x#\n",getoid(master));
	//增加强化技能学习选项。
//	if (!player->get_save("kjh_enhance_sk") )
	{
//		if (player->get_level()>=60
//		&& (present("天恩令",player,1,MAX_CARRY*4) ) )
                {
	               	result += sprintf(ESC"申请学习强化门派技能\ntalk %x# apprentice.15\n",getoid(master));
                }
	}	
        result += ESC"向师傅请安\nCLOSE";
        send_user( player, "%c%s", ':', result );
}

//检查、开放玩家学习强化技能。
void check_enhance_sk(object player,object master)
{
	string name1,name2;
	object item;
	
	name1 = player->get_fam_name();
        name2 = master->get_fam_name();
        
        if ( player->get_save("kjh_enhance_sk") )
        {
        	send_user( player, "%c%s", ':', "你不是已经可以学习强化门派技能了吗！！\n"+ESC+"离开\nCLOSE" );
        	return;
        }
        
	if (!(item=present("天恩令",player,1,MAX_CARRY*4) )
	|| player->get_level()<60
	|| (name1 == "" || name1 != name2 || player->get_fam_master()!=master->get_name() ) )
	{
		send_user( player, "%c%s", ':', "学习本门派的强化技能必须满足以下条件：\n1. 自身门派必须与所学技能门派对应一致；\n2. 玩家当前等级必须≥60；\n3. 玩家必须有强化门派技能学习信物——天恩令！\n你当前不满足以上条件，申请未通过！\n"+ESC+"离开\nCLOSE" );
		return;
	}
	else
	if (item->remove_from_user() )
	{
		destruct(item);
		player->set_save("kjh_enhance_sk",1);
		send_user( player, "%c%s", ':', "你已经可以学习本门派的强化技能了！你可以直接关闭当前对话框，重新点击学习技能就可以了！\n"+ESC"离开\nCLOSE");
		send_user( player, "%c%s", '!', "你申请学习强化门派技能的请求已经通过");
	}
}


void do_quest(object player, object master )
{
	int date, type, level, size, p, x, y, z;
	string npc,cQue,*cTmp;
	object target, item;
	string *Masters;

	if (player->get_save_2("master_hide"))
		return ;
	if ( player->get_save_2("mastertask.type") )
		return ;
	if ( gone_time(player->get_save_2("master.questtime") )< 180 )
	{
		send_user( player, "%c%c%w%s", ':', 3, master->get_char_picid(), master->get_name()+":\n    都怪为师没有好好估算你的能力，以至于你拒绝为师交付的任务。如果你还想再帮为师做事，得给为师一点时间，让为师好好想想该给你些什么任务最为合适。");
		return ;
	}
	player->set_save_2("master.questtime",time());

	type = "sys/task/quest1"->get_random_task(player);
	if (is_god(player))
	{
		if (player->get("lb")) type = player->get("lb");
	}
	player->set("master.type",type);

	switch (type)
	{
	case 1:
		level = player->get_level();
		cTmp = "/sys/task/quest1"->get_random_quest2(level);
		player->set("master.targetname",cTmp);
		cQue = sprintf("%s：\n如今天下世道纷乱不堪，妖魔鬼怪四出肆虐。据说%s，你去替为师捉一个回来，为师要严加审问，看看此乃何物。\n    如果你不知道如何捕抓怪物，打开你的技能界面，选择"HIR"基础"NOR"一栏，在里面就可以找到一个捕抓宠物的技能，将这个技能拖曳到快捷栏中对着怪物使用就可以了，明白了吗？\n", master->get_name(), cTmp[1] );
		break;
	case 2:
		level = player->get_level();
		if ( level < 20 )
			x = NPC_ENERGY_D->get_exp_bonus(level)*10;
		else if ( level < 30 )
			x = NPC_ENERGY_D->get_exp_bonus(level)*15;
		else
			x = NPC_ENERGY_D->get_exp_bonus(level)*20;
		player->set("master.exp",x);
		cQue = sprintf("%s：\n学艺之人只有勤加练习，技艺才可能日近精湛。如此坚持下去，方可领略到本门武学之精华，为师要你提升%d经验来验明你平时是否勤学苦练。\n", master->get_name() ,x);
		break;
	case 3:
		level = player->get_level();
		if ( level < 20 )
			x = 10;
		else if ( level < 30 )
			x = 15;
		else
			x = 20;
		player->set("master.pot",x);
		cQue = sprintf("%s：\n徒儿，要想学到更上乘的武学精要，能力可是最重要的哦！能力只有在实践中磨练出来，为师希望你出去走一走，去磨练一下自己。\n", master->get_name() );
		break;
	case 4:
		player->delete("master.targetname");
		cQue = sprintf("%s：\n%s最近禀报说门里部分物品储备不足，你过去问问，看看有什么能帮忙的地方。\n", master->get_name(), "/sys/task/quest1"->get_manager_name(player->get_fam_name()) );
		break;
	case 5 :
		player->delete_save_2("mastertask.targetname");
		cQue = sprintf("%s：\n%s最近向我禀报说本门需要部分物品以做必备之用，具体情况你直接向他去询问，他每天事务繁多，为师希望你能去帮助他一下。\n", master->get_name(), "/sys/task/quest1"->get_manager_name(player->get_fam_name()) );
		break;
	case 6:
		size = sizeof(locatename);
		p = random(size);
		if (locatename[p]==master->get_fam_name()) p--;
                if (p<0) p = 0;
		npc = mastername[p];
		player->set("master.targetname",npc);
		Masters = locatename - ({ master->get_fam_name()});
		player->set("master.targetcity", locatename[p]);
		cQue =  sprintf("%s：\n为师闭关修行也有些时日了，也不知当年的老友们近况如何。想当初他们常来探访老朽，如果为师不去拜访一下未免有些失礼，%s的%s，徒儿你就替为师问候一下他老人家吧！\n", master->get_name(), locatename[p],npc ) ;
		break;
	case 7 :
		cQue = sprintf("%s：\n为师最近想尝试炼制一种丹药，但炼制这种丹药须得一种灵药做药引，据说只有传闻中的云游商人才有此种灵药。你就试着去寻找一下云游商人，如若找到就向他求得此种灵药！\n", master->get_name() );
		break;
	case 8:
		size = sizeof(cityname);
		npc = cityname[random(size)];
		player->set("master.targetname",npc);
		cQue = sprintf("%s：\n%s的典狱官近日来信，说%s内的治安形势越发严峻，请求本门派几名得力弟子前去协助其维持治安。为师就命你去协助其解决治安混乱问题，望你全力以赴。\n", master->get_name(), npc,npc );
		break;
	case 9:
		z = get_z(master);
		if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) ) return 0;
		x = ( p % 1000000 ) / 1000;  y = p % 1000;
		player->set("mastertask.targetxy",x*1000+y);
		x = x + random(60)-30;
		y = y + random(60)-30;
		if ( x < 1 ) x = 1;
		if ( y < 1 ) y = 1;
		player->set("mastertask.targetxy1",x*1000+y);
		cQue = sprintf("%s：\n有弟子前来禀报说在师门(%d,%d)附近出现了可疑人物，为师命你前去察看一下，如果是些鸡鸣狗盗之类，就尽快打发他们离开，否则本门威信何在？\n", master->get_name(),x,y );
		break;
	case 10:
		Masters = schoolname - ({ player->get_fam_name() });
		size = sizeof(Masters);
		npc = Masters[random(size)];
		player->set("master.targetname",npc);
		cQue = sprintf("%s：\n%s掌门来信邀请本门中人去其门派切磋武艺，以此来弥补各自武学之缺陷。此等机会，你可不能错失了，时间有限，你这就赶过去吧！\n", master->get_name(),npc);
		break;
	case 11:
		cQue = sprintf("%s：\n本门的%s最近好像心神不定，好象是因为本门资金的问题，你最好去找他问问，看有什么可以帮助他。\n", master->get_name(), "/sys/task/quest1"->get_manager_name(player->get_fam_name()) ) ;
		break;
	case 12:
		size = sizeof(cityname);
		npc = cityname[random(size)];
		player->set("master.targetname",npc);
		cQue =sprintf("%s：\n刚收到%s的紧急求助书信，你速去%s找总管，尽量帮其解决困难。\n", master->get_name(), npc, npc ) ;
		break;
	case 13:
	default:
		size = sizeof(cityname);
		npc = cityname[random(size)];
		player->set("master.targetname",npc);
		cQue = sprintf("%s：\n今天刚收到%s王府总管来信说：昨晚%s王府被刺客潜入，%s大王受到惊吓，虽没受伤，但是却让刺客逃掉。总管希望我们能派人协助他捉拿刺客。为师就命你前去走一趟吧！\n", master->get_name(), npc,npc, npc ) ;
		break;
	}

	if ( !stringp(cQue) )
		return;
	cQue += sprintf("今日已累计任务次数：%d次\n"ESC"接受 \ntalk %x# accept_quest\n"+ESC"拒绝\ntalk %x# apprentice.13\n",player->get_save_2("mastertask.count"),getoid(master),getoid(master));
	send_user( player, "%c%c%w%s", ':', 3, master->get_char_picid(), cQue);
}

void check_random_bonus(object player)
{
	string *book, name, result;
	int size, date,rate;
	object obj;
	if (MAIN_D->get_host_type()==1||MAIN_D->get_host_type()==1000)
	{
		obj = new("item/sell/0021");
		date = obj->move(player,-1);
		if ( !date )
			destruct(obj);
		else
		{
			send_user( player, "%c%s", '!', "你得到一张财神符！" );
			obj->add_to_user(date);
		}
	}
	rate = random(10000);
	if ( rate < 1000 )
	{
		obj = new("item/std/8000");
		date = obj->move(player,-1);
		if ( !date )
			destruct(obj);
		else
		{
			send_user( player, "%c%s", '!', "你得到藏宝图" );
			obj->add_to_user(date);
		}

	}
	else if ( rate < 1100 )
	{
		obj = new("item/44/4488");
		date = "quest/pet"->get_drop_skill1();
		if ( date )
			obj->set("special",sprintf("%d",date));
		date = obj->move(player,-1);
		if ( !date )
			destruct(obj);
		else
		{
			send_user( player, "%c%s", '!', "你得到精元丹" );
			obj->add_to_user(date);
		}
	}
	else if ( rate < 1400 )
	{
		name = player->get_fam_name();
		if (!name) return;
		book = FamilyBook[name];
		size = sizeof(book);
		if (size==0) return;
		obj = new (sprintf("/item/95/%s", book[random(size)]));
		if (!obj) return;
		if( USER_INVENTORY_D->can_carry(player, obj)  >=1 )
		{
			date =obj->move(player, -1);
			obj->add_to_user(date);
			result = sprintf("你意外得到一本%s。", obj->get_name());
			send_user( player, "%c%s", '!', result );
		}
		else
		{
			destruct(obj);
		}
		return;
	}
	else if ( rate < 1405 )
	{
		name = player->get_fam_name();
		if (!name) return;
		size = sizeof(giftname);
		if (size==0) return;
		obj = new (sprintf("/item/96/%s", giftname[random(size)]));
		if (!obj) return;
		if( USER_INVENTORY_D->can_carry(player, obj)  >=1 )
		{
			date =obj->move(player, -1);
			obj->add_to_user(date);
			result = sprintf("你意外得到一本%s。", obj->get_name());
			send_user( player, "%c%s", '!', result );
		}
		else
		{
			destruct(obj);
		}
		return;
	}
}

//检查每次增加经验和潜能处
void check_quest(object me,  int point, int type)
{
	if ( point<0 ) return;
	if (!me->get_fam_name() ) return;
	if (type>3||type<2) return;
	if ( me->get_save_2("mastertask.type")!=type) return;
	if (me->get_save_2("mastertask.status")==99) return;
	me->add_save_2("mastertask.targetxy", point );
	if (me->get_save_2("mastertask.targetxy")>=me->get_save_2("mastertask.targetpic"))
	{
		me->set_save_2("mastertask.status", 99);

		if (type==2) send_user (me, "%c%s", '!', sprintf("第"HIY" %d "NOR"个任务，本次历练任务完成，回师门禀告师傅。\n", me->get_save_2("mastertask.time")+1) );
		else send_user (me, "%c%s", '!', sprintf("第"HIY" %d "NOR"个任务，本次游历任务完成，回师门禀告师傅。\n", me->get_save_2("mastertask.time")+1) );

	}
	send_task_desc(me,1);
}

// 函数：采购任务 掌门及王爷
int accept_object( object who, object player, object obj )
{
        string name1, name2, result;
        int date, level, time, exp, pot, type, size;
        object gift;

        name1 = who->get_fam_name();
        name2 = player->get_fam_name();

        player->to_front_eachother(who);
        type = player->get_save_2("mastertask.type");
	level = player->get_level();
	time = player->get_save_2("mastertask.time");
	if (type==6 && player->get_save_2("mastertask.giftname")==obj->get_name() && player->get_save_2("mastertask.targetname")==who->get_name()&& player->get_save_2("mastertask.status")==2)
	{
		player->set_save_2("mastertask.giftname",0);
		//有50%的机率获得特殊物品
		if (!random(2))
		{
			size = sizeof(giftname);
			name1 = giftname[random(size)];
			gift = new (sprintf("/item/95/%s.c", name1));
		}
		else
		{
			gift = new ("/item/44/4488");
		}
		if (gift)
		{
			if( USER_INVENTORY_D->can_carry(player, gift)  >=1 )
			{
				date =gift->move(player, -1);
				gift->add_to_user(date);
				if (player->get_gender()==1)
					result = sprintf("%s\n嗯，小兄弟看来前途无量啊，这本破书我留着也没多大用处，就送给你吧。", who->get_name());
				else
					result = sprintf("%s\n嗯，小姑娘看来前途无量啊，这本破书我留着也没多大用处，就送给你吧。", who->get_name());
				send_user( player, "%c%c%w%s", ':',3,who->get_char_picid(), result );
			}
			else
			{
				if (player->get_gender()==1)
					result = sprintf("%s\n嗯，小兄弟看来前途无量啊，我本想送你点东西，无奈拿不出手啊。", who->get_name());
				else
					result = sprintf("%s\n嗯，小姑娘看来前途无量啊，我本想送你点东西，无奈拿不出手啊。", who->get_name());
				send_user( player, "%c%c%w%s", ':',3,who->get_char_picid(), result );
				destruct(gift);
			}
		}
		else
			send_user( player, "%c%c%w%s", ':',3,who->get_char_picid(), who->get_name()+":\n    呵呵，如今的后辈还真懂得不少人情世故。老夫我也不客气收下了。" );
		return 1;
	}

        return 0;
}

// 函数：司库接收物品
int accept_object2( object who, object player, object obj )
{
        string name1, name2, result;
        int date, level, time, exp, pot, type, size;
        object gift;

        name1 = who->get_fam_name();
        name2 = player->get_fam_name();

        player->to_front_eachother(who);
        if (name1!=name2) return 0;
        type = player->get_save_2("mastertask.type");
        if ( type != 4  )
        	return 0;
        name1=player->get_save_2("mastertask.targetname");
        name2=obj->get_name();
	if (  name1==name2 || "男装"+name2 == name1 || "女装"+name2 == name1 )
	{
//		if ( type == 5 )
//		{
//			player->add_save_2("mastertask.targetxy",-1*obj->get_amount());
//			if ( player->get_save_2("mastertask.targetxy") > 0 )
//			{
//				send_user( player,"%c%c%w%s", ':',3,who->get_char_picid(),sprintf("%s：\n    谢谢啊，这正是我需要的。请继续努力哦～", who->get_name() ) );
//				return 1;
//			}
//		}
		if ( obj->is_combined() )
			obj->add_amount(-1);
		else
		{
			obj->remove_from_user();
			destruct(obj);
		}
		task_bonus(player,who);
		send_user( player, "%c%c%w%s", ':',3,who->get_char_picid(), sprintf("%s：\n    不错，这么快就把东西找回来了，看来我没有选错人啊！我已经向师傅禀明了你的功劳，这是师傅给你的奖励。", who->get_name() ) );
		return -99;
	}
	else
	{
		send_user( player, "%c%c%w%s", ':',3,who->get_char_picid(),sprintf("%s：\n    这物品好象不是我让你采购的吧！做事情要细心啊！不然师傅知道了会怪罪于你。", who->get_name() ) );
		return 0;
	}
	return 0;
}

// 帮派司库，王府总管接受财物

int accept_money( object who, object player, int gold )
{
	string name, gift;
	if (gold<500) return 0;
        if (who->get_city_name() )
	if (who->get_fam_name()!="" && who->get_fam_name()!=player->get_save_2("mastertask.targetcity") ) return 0;
	if (who->get_city_name()!="" && who->get_city_name()!=player->get_save_2("mastertask.targetcity") ) return 0;
	if (sizeof(who->get_fam_name())) name = "本门掌门";
	else name = "王爷";
	if ( player->get_save_2("mastertask.type")==6 && player->get_save_2("mastertask.status")<=2 )
	{
		gift = COLLECT_FILE->get_collect_name();
		player->set_save_2("mastertask.giftname", gift);
		if (player->get_gender()==1)
			send_user( player, "%c%s", ':', sprintf("%s：\n哈哈，这位小兄弟真有趣，这样吧，我偷偷告诉你一个小秘密，%s目前想找"HIR"%s"NOR"。", who->get_name(), name, gift ) );
		else
			send_user( player, "%c%s", ':', sprintf("%s：\n哈哈，这位小姑娘真有趣，这样吧，我偷偷告诉你一个小秘密，%s目前想找"HIR"%s"NOR"。", who->get_name(), name, gift ) );
		player->set_save_2("mastertask.status", 2);
		return 1;
	}
	return 0;
}
//拜访任务
int do_look2(object player, object master )
{
	string result = "";
        if ( player->get_save_2("mastertask.type")==6 && master->get_name() == player->get_save_2("mastertask.targetname") )
        {
        	if ( player->get("master.type") != 69)
        	{
        		player->set("master.type", 69);
        		send_user( player, "%c%c%w%s", ':',3,master->get_char_picid(), sprintf("%s：\n呵呵……你师傅还记得让人来拜望老夫，老夫不枉交了这个朋友啊！让你师傅放心！我身体很好，找个时间我还想和你师傅切磋一下棋艺呢！\n"ESC"完成任务\nlook %x#\n", master->get_name(),getoid(master) ) );
        	}
        	else
        	{
 			player->set("master.type",0);
			task_bonus(player,master);
        	}
        	return 1;
        }

        return 0;
}

//典狱官的 do_look
string do_look_quest6(object player, object master )
{
	string id;
	object npc;
	if ( master->get_city_name() != player->get_save_2("mastertask.targetname") )
		return "";
	if ( player->get_save_2("mastertask.type") != 8 )
		return "";
	if ( player->get_save_2("mastertask.status")==1&&( !stringp( id = player->get_save_2("mastertask.target") ) || ( !objectp(npc = find_char(id)) ) || npc->get("user")!=player->get_number() ))
		return "";
	return sprintf(ESC"协助治安\ntalk %x# accept_task\n",getoid(master));
}
//典狱官 协助治安任务
void accept_task11(object player, object master )
{
	int status, x, y, z, p, level;
	object map, npc, *target;
	string name;

	if (player->get_save_2("mastertask.type")==8 && master->get_city_name() == player->get_save_2("mastertask.targetname") )
	{

		status = player->get_save_2("mastertask.status");
		switch(status)
		{
		case 0:		//刚接到任务
			player->set_save_2("mastertask.status", 1);
			z = get_z(master);
			if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) ) return 0;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			level = player->get_level();
			npc = new( "npc/task/master_1" );
			if (!npc) return 0;
			npc->set("level", level);
			npc->set_level(level);
			NPC_ENERGY_D->init_level(npc, level);
			npc->add_max_hp( npc->get_max_hp()/10*3 );
			npc->set_walk_speed( 6 );
			npc->set_attack_speed( 15 );
			npc->set_char_type(FIGHTER_TYPE_2);
			npc->set_char_picid(0251);
			npc->add_to_scene(z, x, y, 3);
			map->add_reset(npc);    // 加入复位列表
			npc->set("user", player->get_number());
			npc->set_name(sprintf("造谣的混混(%d)", player->get_number()));
			player->set_save_2("mastertask.target", sprintf("%x#",getoid(npc)));
			player->set_save_2("mastertask.targetxy", x*1000+y );
			player->set_save_2("mastertask.status", 1);
			x = x + random(60)-30;
			y = y + random(60)-30;
			if ( x < 1 ) x = 1;
			if ( y < 1 ) y = 1;
			player->set_save_2("mastertask.targetxy1", x*1000+y );
			send_user( player, "%c%s", ':',
				sprintf("%s：\n    %s门派果然不凡，派出如此身手矫健之人来协助。我刚接到手下信报，说城外有人在造谣生事，蛊惑民心。麻烦你代我跑一趟，处理一下就好。那小贼应该就在（%d，%d）一带出没。为了行事方便，你最好利用我们官府的缉捕公文来确认造谣的混混的下落。",
				master->get_name(), player->get_fam_name(),x,y) );
			send_task_desc(player,0);
			break;
		case 1:
			x = player->get_save_2("mastertask.targetxy1");
			y = x % 1000;
			x = x / 1000;
			send_user( player, "%c%s", ':', sprintf("%s：\n    据说那造谣生事的流氓和混混仍未伏法。那小贼应该就在（%d，%d）一带出没。你最好利用我们官府的缉捕公文来确认其下落，这样会更方便你解决问题", master->get_name(),x,y) );
			break;
		case 2:
			send_user( player, "%c%s", ':', sprintf("%s：\n不愧为贵门得力弟子，办事如此迅速，身手如此非凡，真乃少年英雄啊！\n"ESC"完成任务\ntalk %x# accept_task", master->get_name(),getoid(master)) );
			player->set_save_2("mastertask.status", 99);
			break;
		case 99:
			task_bonus(player,master);
			break;
		default:
			return ;
		}
		return ;
	}
	return ;
}

//门派切磋弟子的 do_look
int do_look_quest8(object player, object master )
{
	int status, family, p, x, y, z, level, d, pic;
	string result, cityname;
	object npc, map, cityobj;
	if (player->get_save_2("mastertask.type")==10)
	{
		status = player->get_save_2("mastertask.status");
		if (status!=99 && master->get_fam_name()==player->get_save_2("mastertask.targetname") )
		{
			result = sprintf("%s\n    你就是%s派来切磋武艺的吗？看你一副瘦弱的样子……怎么会经打？……我师兄可不会手下留情的。你确定要挑战吗？\n"ESC"马上挑战！\ntalk %x# accept_quest\n"ESC"我还是先准备准备再来挑战。\nclose\n",master->get_name(),player->get_fam_name(),getoid(master));
			send_user(player,"%c%c%w%s",':',3,master->get_char_picid(),result);
			return 1;
		}
	}
//	if (player->get_save_2("masterfight.status")==1 && master->get_fam_name()==player->get_fam_name())
//	{
//		result = sprintf("%s：\n弟子%s，前来向师叔请教，不知师叔是否在内？\n\n%s：\n那好，你进去吧。",
//			player->get_name(), player->get_name(), player->get_fam_name());
//		send_user( player, "%c%s", ':', result );
//		if( ( z = find_map_flag(1000, 2999, 0) ) <= 0 ) return 1;
//		x = ( p % 1000000 ) / 1000;  y = p % 1000;
//		level = player->get_save_2("masterfight.targetxy");
//		npc = new( "npc/90/app_fight" );
//		if (!npc) return 0;
//		npc->set("level", level);
//		switch(master->get_fam_name())
//		{
//		case "桃花源":
//		        family = 10;
//		        d = 891;
//		        cityname = "桃花岛";
//		        break;
//		case "蜀山":
//		        family = 20;
//		        d = 892;
//		        cityname = "蜀岭峰";
//		        break;
//		case "禁卫军":
//		        family = 30;
//		        d = 893;
//		        cityname = "禁卫军营地";
//		        break;
//		case "唐门":
//		        family = 40;
//		        d = 894;
//		        cityname = "唐门密室";
//		        break;
//		case "茅山":
//		        family = 50;
//		        d = 895;
//		        cityname = "鬼门府";
//		        break;
//		case "昆仑山":
//		        family = 60;
//		        d = 896;
//		        cityname = "昆仑仙境";
//		        break;
//		default:
//		        family = 70;
//		        d = 897;
//		        cityname = "死亡沼泽";
//		        break;
//		}
//                init_virtual_map(z, d);
//                map = new( NEWBIE );
//                map->set_client_id(d);
//                map->set_owner(player);
//                set_map_object( map, map->set_id(z) );
//                map->set_name(cityname);
//                p = get_jumpin(z, 1);
//		NPC_ENERGY_2_D->init_family(npc, family, level, -1);
//		npc->set_fam_name(master->get_fam_name());
//		npc->set_char_type(FIGHTER_TYPE_2);
//		npc->set_name(sprintf("%s的师叔", player->get_name()));
//		npc->init_pic(npc, family);
//		x = p/1000, y = p % 1000;
//		npc->add_to_scene(z, x, y, 3);
//		npc->set("user", player->get_number());
//                player->set_2("masterfight.x", get_x(player));
//		player->set_2("masterfight.y", get_y(player));
//		player->set_2("masterfight.z", get_z(player));
//		if( p = get_valid_xy(z, x, y, IS_CHAR_BLOCK) )
//                {
//                        x = p/1000, y = p % 1000;
//                        player->add_to_scene(z, x, y, 3);
//
//                }
//		return 1;
//	}
	TASK_APPRENTICE_D->do_look(player, master);

}
//门派切磋
void accept_quest8(object player, object master,string arg)
{
	int status, family, p, x, y, z, level, d, pic;
	string result, cityname,id;
	object npc, map, cityobj;
	if (player->get_save_2("mastertask.type")!=10)
		return ;
	status = player->get_save_2("mastertask.status");
	if (master->get_fam_name()==player->get_save_2("mastertask.targetname") )
	{
		if ( status != 99 )
		{
			player->set_save_2("mastertask.status", 1);
			if ( stringp( id = player->get_save_2("mastertask.target") ) && ( npc = find_char(id) ) && npc->get("user")==player->get_number() )
			{
				player->set_2("mastertask.x", get_x(player));
				player->set_2("mastertask.y", get_y(player));
				player->set_2("mastertask.z", get_z(player));
				player->add_to_scene(get_z(npc), get_x(npc), get_y(npc), 3);
				npc->set_hp(npc->get_max_hp());
				npc->set_mp(npc->get_max_mp());
				npc->set_char_type(FIGHTER_TYPE_2);
				SAY_CMD->say( npc, npc->get_name()+"，前来讨教！");
				return ;
			}
			if( ( z = find_map_flag(1000, 2999, 0) ) <= 0 ) return ;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			level = player->get_level();
			npc = new( "npc/task/master_5" );
			if (!npc) return;
			npc->set("level", level);
			switch(master->get_fam_name())
			{
			case "桃花源":
			        family = 10;
			        d = 891;
			        cityname = "桃花岛";
			        break;
			case "蜀山":
			        family = 20;
			        d = 892;
			        cityname = "蜀岭峰";
			        break;
			case "禁卫军":
			        family = 30;
			        d = 893;
			        cityname = "禁卫军营地";
			        break;
			case "唐门":
			        family = 40;
			        d = 894;
			        cityname = "唐门密室";
			        break;
			case "茅山":
			        family = 50;
			        d = 895;
			        cityname = "鬼门府";
			        break;
			case "昆仑山":
			        family = 60;
			        d = 896;
			        cityname = "昆仑仙境";
			        break;
			default:
			        family = 70;
			        d = 897;
			        cityname = "死亡沼泽";
			        break;
			}
	                init_virtual_map(z, d);
	                map = new( NEWBIE );
	                map->set_client_id(d);
	                set_map_object( map, map->set_id(z) );
	                map->set_name(cityname);
	                map->set_owner(player);
	                p = get_jumpin(z, 1);
			npc->set_level(level);
			NPC_ENERGY_D->init_level(npc, level);
			npc->add_max_hp( npc->get_max_hp()*3 );
			npc->add_dp( npc->get_dp()/2);
			npc->add_pp( npc->get_pp()/2);
			npc->set_walk_speed( 3 );
			npc->set_attack_speed( 10 );
			npc->set_fam_name(master->get_fam_name());
			npc->set_char_type(FIGHTER_TYPE_2);
			npc->set_name(sprintf("%s弟子", master->get_fam_name()));
			npc->init_pic(npc, family);
			x = p/1000, y = p % 1000;
			npc->add_to_scene(z, x, y, 3);
			map->add_reset(npc);    // 加入复位列表
			npc->set("user", player->get_number());
			player->set_save_2("mastertask.target", sprintf("%x#",getoid(npc)));
			player->set_2("mastertask.x", get_x(player));
			player->set_2("mastertask.y", get_y(player));
			player->set_2("mastertask.z", get_z(player));
			if( p = get_valid_xy(z, x, y, IS_CHAR_BLOCK) )
	                {
	                        x = p/1000, y = p % 1000;
	                        player->add_to_scene(z, x, y, 3);
	                }
	                SAY_CMD->say( npc, npc->get_name()+"，前来讨教！");
			return ;

		}
	}
}

//帮派司库的 do_look
int do_look_quest9(object player, object master )
{
	string name1, name2, result = "",*nTmp;
	object obj, *inv;
	int p, level, i, size,type;
        name1 = player->get_fam_name();
        name2 = master->get_fam_name();
        // 取消多余的银票
        obj = present("银票", player, 1, MAX_CARRY*4);
        if (objectp(obj)&&player->get_save_2("mastertask.type")!=11)
        {
                send_user(player, "%c%s", '!', "你身上的银票消失了。");
                obj->remove_from_user();
                destruct(obj);
        }

        if (player->get_save_2("mastertask.type")==6)
        {
        	if (player->get_save_2("mastertask.status")==0 && player->get_save_2("mastertask.targetcity")==master->get_fam_name())
        	{
        		player->set_save_2("mastertask.status", 1);
        		send_user( player, "%c%s", ':', sprintf("%s：\n本门掌门不但武艺超群，而且对各种古董字画有很深的了解，平时喜好聚众友一起品茶赏画。\n"ESC"给他500文钱，透露点风声。\ngive %x# 0#0 0#0 0#0 0#0 0#0 0#0 $500\n"ESC"我没兴趣知道。\nclose", master->get_name(),getoid(master)) );
        		return 1;
        	}
        }
        if (name1=="" || name1!=name2)
        {
        	TASK_APPRENTICE_D->do_look(player, master);
        	return 1;
        }
        if ((type=player->get_save_2("mastertask.type"))==4 )
        {
        	if (player->get_save_2("mastertask.status")==0)
        	{
        		result = TASK_APPRENTICE_D->get_chat(player, master);

        		result = result +"\n"
        			ESC + sprintf("采购任务\ntalk %x# accept_task.1\n",getoid(master));
        		send_user( player, "%c%s", ':', result );
        		player->set("master.type",4);
//			player->delete("master.targetname");

	        	return 1;
	        }
	        else
	        if (player->get_save_2("mastertask.status")<99)
	        {
	                result = sprintf("%s：\n    采购物品，不要盲目，要注意其所对应的地方。采购齐全之后用给予的方式（快捷键ALT+G）交给我就可以了\n"
	                        ESC"离开。\nCLOSE\n",
	                        master->get_name() );
	        	send_user( player, "%c%s", ':', result );
	        	player->set("master.type",5);
	        	return 1;
	        }
	        return 1;
        }
        else if (type==5 )
        {
        	if (player->get_save_2("mastertask.status")==0)
        	{
        		result = TASK_APPRENTICE_D->get_chat(player, master);

        		result = result +"\n"
        			ESC + sprintf("收集任务\ntalk %x# accept_task.2\n",getoid(master));
        		send_user( player, "%c%s", ':', result );
        		player->set("master.type",5);
	        	return 1;
	        }
	        else
	        if (player->get_save_2("mastertask.status")<99)
	        {
	        	task_finish9(player,master);
	        	return 1;
	        }
	        return 1;
        }
        else if (type==11)
        {
                name1 = player->get_name(); name2 = master->get_name();
        	if (player->get_save_2("mastertask.status")==0)
        	{
                        if( present("银票", player, 1, MAX_CARRY*4) )
                        {
                                send_user(player, "%c%s", '!', "您已经领了银票了。");
                                return 1;
                        }
        		obj = new("/item/std/0003");
                       	obj->set_orgin_money(50000);
                        obj->set_money(50000);
                        if (USER_INVENTORY_D->can_carry(player, obj) < 1 )
                        {
                        	send_user (player, "%c%s", ';', "道具栏已满，领取任务物品失败");
                        	destruct(obj);
                        	return 1;
                        }
                        if( p = obj->move(player, -1) ) obj->add_to_user(p);
                        else destruct(obj);
			player->set_save_2("mastertask.status", 1);
			player->set_save_2("mastertask.targetxy", player->get_level()*500+20000);
			send_user( player, "%c%s", ':', sprintf("%s：\n    唉，最近门里的开销越来越大，钱库都快见底了。既然师傅让你来帮忙，自然是看中了你的经商头脑。来，这是本金，你下山去做做小生意，赚些钱回来交差吧！", name2 ) );
			send_user( player, "%c%s", '!', "你获得了通商银票" );
			player->set_save_2("mastertask.endtime", time()+7200);
			player->add_exp(20);
			send_user ( player, "%c%s", ';', "你得到20点经验");
			send_task_desc(player,0);
			return 1;
        	}
        	else
                if (player->get_save_2("mastertask.status")==1)
        	        send_user( player, "%c%s", ':', sprintf("%s：\n    做生意呢？要动动脑筋，比较一下各地之间物品的差价，低买高卖，这是最简单的生意经了。", master->get_name()) );
                else
                if (player->get_save_2("mastertask.status")==98)
                {
                        inv = all_inventory(player, 1, MAX_CARRY*4);
                        size = sizeof(inv);
                        if (size>0)
                        {
                                for (i=0;i<size;i++)
                                {
                                        if (inv[i]->get_item_type()==ITEM_TYPE_GOOD)
                                        {
						inv[i]->remove_from_user();
						destruct(inv[i]);
                                        }
                                }
                        }
                        obj = present("银票", player, 1, MAX_CARRY*4);
                        if (obj->get_money()-obj->get_orgin_money()<player->get_save_2("mastertask.targetxy"))
                        {
                                send_user( player, "%c%s", ':', sprintf("%s：\n您身上的银票数目好象不对啊。。。。", master->get_name()) );
                                return 1;
                        }
                        obj->remove_from_user();
                        destruct(obj);
                        player->set_save_2("mastertask.status", 99);
                        send_user( player, "%c%s", ':', sprintf("%s：\n哈哈，我果然没看错人。你的确是个经商的天才～\n"ESC"完成任务\nlook %x#\n", master->get_name(),getoid(master)) );
                        return 1;
                }
                else
                if (player->get_save_2("mastertask.status")==99)
                {
                	task_bonus(player,master);
                }
                return 1;
        }
        TASK_APPRENTICE_D->do_look(player, master);
}
//王府总管的 do_look
int do_look_quest10(object player, object master )
{
	string name1, npc, result = "";
	string *Citys;
	object target,map;
	int p, status, size, x, y, z, level, i,x1,y1;
	string *targetnpc;
        name1 = master->get_city_name();
        if (player->get_save_2("mastertask.type")==6)
        {
        	if (player->get_save_2("mastertask.status")==0 && player->get_save_2("mastertask.targetcity")==master->get_city_name())
        	{
        		player->set_save_2("mastertask.status", 1);
        		send_user( player, "%c%s", ':', sprintf("%s：\n我家王爷雄才大略，不过在闲时也喜欢收集一些小玩艺，这不，我还刚准备去外头转转，看能找些什么回来孝敬王爷呢。\n"ESC"给他500文钱，透露点风声。\ngive %x# 0#0 0#0 0#0 0#0 0#0 0#0 $500\n"ESC"我没兴趣知道。\nclose", master->get_name(),getoid(master)) );
        		return 1;
        	}
        	return 0;
        }
        if (player->get_save_2("mastertask.type")==12)
        {
        	if ( player->get_save_2("mastertask.targetname") != master->get_city_name() )
        		return 0;
        	status = player->get_save_2("mastertask.status");
        	if (status==0)
        	{
        		Citys = cityname - ({ name1 });
        		size= sizeof(Citys);
        		npc = Citys[random(size)];
        		player->set_save_2("mastertask.giftname", npc);
        		z = get_city_number(npc);
        		if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;
			target = new ("/npc/task/master_3.c");
			if (!target) return 0;
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) ) return 0;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			x1 = x + random(60)-30;
			y1 = y + random(60)-30;
			if ( x1 < 1 ) x1 = 1;
			if ( y1 < 1 ) y1 = 1;
        		send_user( player, "%c%s", ':', sprintf("%s：\n    不瞒你说，此次求助是因为本国的一位高官不知何故，突然叛逃出国。他太了解本国的机密事宜，如果向敌国泄漏机密，后果绝对是不堪设想……\n    我刚刚收到确切的信报，说他正在%s(%d,%d)一带逃窜。他好象已经买通了那一带的山贼流氓来充当他的贴身保镖。\n    真担心他将本国的机密事宜泄漏出去，最保险的办法只有杀掉他。", master->get_name(), npc,x1,y1 ) );
			level = player->get_level();
			target->set("level", level);

			target->set_level(level+5);
			NPC_ENERGY_D->init_level(target, level+5);
			target->add_max_hp( target->get_max_hp()*3 );
			target->add_dp( target->get_dp()/2);
			target->add_pp( target->get_pp()/2);
			target->set_walk_speed( 3 );
			target->set_attack_speed( 10 );

			target->set_char_type(FIGHTER_TYPE_2);
			target->set_char_picid(0053);
			target->set_name(sprintf("叛逃官员(%d)", player->get_number()) );
			target->add_to_scene(z, x, y, 3);
			map->add_reset(target);    // 加入复位列表
			target->set("user", player->get_number());
			targetnpc = ({ sprintf("%x#",getoid(target)) });

			player->set_save_2("mastertask.targetpic", "叛逃官员");
			player->set_save_2("mastertask.status", 1);
			player->set_save_2("mastertask.targetxy", x*1000+y);

			target = new ("/npc/task/master_3.c");
			if( !( p = get_valid_xy( z, x, y, IS_CHAR_BLOCK ) ) ) return 0;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			level = player->get_level();
			target->set("level", level);
			target->set_level(level);
			NPC_ENERGY_D->init_level(target, level);
			target->add_max_hp( target->get_max_hp() );
			target->set_walk_speed( 4 );
			target->set_attack_speed( 15 );
			target->set_char_type(FIGHTER_TYPE_2);
			target->set_name(sprintf("随从(%d)", player->get_number()) );
			target->set_char_picid(0052);
			target->add_to_scene(z, x, y, 3);
			map->add_reset(target);    // 加入复位列表
			target->set("user", player->get_number());
			targetnpc += ({ sprintf("%x#",getoid(target)) });
			target = new ("/npc/task/master_3.c");
			if( !( p = get_valid_xy( z, x, y, IS_CHAR_BLOCK ) ) ) return 0;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			level = player->get_level();
			target->set("level", level);

			target->set_level(level);
			NPC_ENERGY_D->init_level(target, level);
			target->add_max_hp( target->get_max_hp() );
			target->set_walk_speed( 4 );
			target->set_attack_speed( 15 );

			target->set_char_type(FIGHTER_TYPE_2);
			target->set_name(sprintf("随从(%d)", player->get_number()) );
			target->set_char_picid(0052);
			target->add_to_scene(z, x, y, 3);
			map->add_reset(target);    // 加入复位列表
			target->set("user", player->get_number());
			targetnpc += ({ sprintf("%x#",getoid(target)) });
			player->set_save_2("mastertask.target",implode(targetnpc,"|"));
			player->set_save_2("mastertask.targetxy1",x1*1000+y1);
			player->add_exp(50);
			send_user ( player, "%c%s", ';', "你得到50点经验");
			send_task_desc(player,0);
			return 1;
        	}
        	else
        	if (status ==4)
        	{
        		if (random(100)<30)
        		{
        			player->set_save_2("mastertask.status", 99);
				send_user( player, "%c%s", ':', sprintf("%s：\n这实在是天大的好消息，为了感谢贵门对本国的鼎力相助。这是本国备下的小小礼物，还请笑纳。\n"ESC"完成任务\nlook %x#", master->get_name(),getoid(master)) );
        		}
        		else
        		{
        			player->set_save_2("mastertask.status", 98);
        			send_user( player, "%c%s", ':', sprintf("%s：\n实在是太好了，本国对贵门给予的协助将铭记不忘。\n"ESC"完成任务\nlook %x#", master->get_name(),getoid(master) ) );
        		}
			return 1;

        	}
        	else
        	if (status ==98)
        	{
			task_bonus(player,master);
			return 1;
        	}
        	else
        	if (status ==99)
        	{
			target = new (sprintf("/item/91/%d",9160+random(8)));
			if( USER_INVENTORY_D->can_carry(player, target)  >=1 )
			{
				p =target->move(player, -1);
				target->add_to_user(p);
				task_bonus(player,master);
				return 1;
			}
			else
			{
				notify( "您携带的东西太多了。" );
				destruct(target);
			}
			return 1;
        	}
        	else
        	{
        		send_user( player, "%c%c%w%s", ':',3,master->get_char_picid(), sprintf("%s：\n    现在真是心如刀麻啊！大王一天问我几次事态进展，我都无言以对，还望%s多多费心了。\n"ESC"离开", master->get_name(),NPC_RANK_D->get_respect_2(player)) );
        		return 1;
        	}
        	return 0;
        }
        if (player->get_save_2("mastertask.type")==13)
        {
        	if ( player->get_save_2("mastertask.targetname") != master->get_city_name() )
        		return 0;
        	status = player->get_save_2("mastertask.status");
        	if (status==0)
        	{
        		Citys = cityname - ({ name1 });
        		size= sizeof(Citys);
        		npc = Citys[random(size)];

        		player->set_save_2("mastertask.giftname", npc);
        		z = get_city_number(npc);
        		if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;
			target = new ("/npc/task/master_4.c");
			if (!target) return 0;
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) ) return 0;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			x1 = x + random(60)-30;
			y1 = y + random(60)-30;
			if ( x1 < 1 ) x1 = 1;
			if ( y1 < 1 ) y1 = 1;
			send_user( player, "%c%s", ':', sprintf("%s：\n快……快，刚收到探子消息，他们跟踪那些刺客到了%s后，就失去了踪迹。不过我相信那些刺客不会逃得太远，应该还藏匿在%s(%d,%d)一带。还望少侠速去查探一番，一旦发现刺客，格杀勿论。", master->get_name(),npc,npc,x1,y1) );
			level = player->get_level();
			target->set("level", level);

			target->set_level(level);
			NPC_ENERGY_D->init_level(target, level+2);
			target->add_max_hp( target->get_max_hp()*4 );
			target->add_dp( target->get_dp()/5*4);
			target->add_pp( target->get_pp()/5*4);
			target->set_walk_speed( 3 );
			target->set_attack_speed( 10 );
			target->set_char_type(FIGHTER_TYPE_2);
			target->set_char_type(FIGHTER_TYPE_2);
			target->set_name(sprintf("刺客首领(%d)", player->get_number()) );
			target->set_char_picid(1000);
			target->add_to_scene(z, x, y, 3);
			map->add_reset(target);    // 加入复位列表
			target->set("user", player->get_number());
			targetnpc = ({ sprintf("%x#",getoid(target)) });
			for (i=0;i<4;i++)
			{
				target = new ("/npc/task/master_4.c");
				if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) ) return 0;
				x = ( p % 1000000 ) / 1000;  y = p % 1000;
				level = player->get_level();
				target->set("level", level);
				target->set_level(level);
				NPC_ENERGY_D->init_level(target, level+2);
				target->add_max_hp( target->get_max_hp() );
				target->add_dp( target->get_dp()/5);
				target->add_pp( target->get_pp()/5);
				target->set_walk_speed( 4 );
				target->set_attack_speed( 15 );
				target->set_char_type(FIGHTER_TYPE_2);
				target->set_name(sprintf("蒙面刺客(%d)", player->get_number()) );
				target->set_char_picid(202);
				target->add_to_scene(z, x, y, 3);
				map->add_reset(target);    // 加入复位列表
				target->set("user", player->get_number());
				targetnpc += ({ sprintf("%x#",getoid(target)) });
			}
			player->set("targets", targetnpc );
			player->set_save_2("mastertask.status", 1);
			player->set_save_2("mastertask.targetxy", x*1000+y);
			player->set_save_2("mastertask.targetxy1", x1*1000+y1);
			player->set_save_2("mastertask.target",implode(targetnpc,"|"));
			player->set_save_2("mastertask.x",0);
			player->set_save_2("mastertask.y",0);
			player->add_exp(50);
			send_user ( player, "%c%s", ';', "你得到50点经验");
			send_task_desc(player,0);
			return 1;
        	}
        	else
        	if (status ==6)
        	{
        		if (random(100)<50)
        		{
        			player->set_save_2("mastertask.status", 99);
				send_user( player, "%c%s", ':', sprintf("%s：\n这真是天大的好消息，本总管马上把此消息禀告于王爷。这是王爷给%s备下的礼物，聊表敬意，还望笑纳。\n"ESC"完成任务\nlook %x#", master->get_name(),NPC_RANK_D->get_respect_2(player),getoid(master)) );
        		}
        		else
        		{
        			player->set_save_2("mastertask.status", 98);
        			send_user( player, "%c%s", ':', sprintf("%s：\n实在是太好了，王爷知道这消息肯定会非常高兴。\n"ESC"完成任务\nlook %x#", master->get_name(),getoid(master) ) );
        		}
			return 1;

        	}
        	else
        	if (status ==98)
        	{
			task_bonus(player,master);
			return 1;
        	}
        	else
        	if (status ==99) //九转丹或者混天丹、同等级的随机配方（三选一）
        	{
        		if ( random(2)  )
				target = new ("/item/std/0086");
			else
				target = new ("/item/std/0087");
			if( USER_INVENTORY_D->can_carry(player, target)  >=1 )
			{
				p =target->move(player, -1);
				target->add_to_user(p);
				task_bonus(player,master);
				return 1;
			}
			else
			{
				notify( "您携带的东西太多了。" );
				destruct(target);
			}
			return 1;
        	}
        	else
        	{
        		send_user( player, "%c%c%w%s", ':',3,master->get_char_picid(), sprintf("%s：\n    大王刚才又召我觐见，问我刺客是否捉到？我真不知该如何回答，真担心如此下去，大王定降罪于我。还望%s多多费心了。\n"ESC"离开", master->get_name(),NPC_RANK_D->get_respect_2(player)) );
        		return 1;
        	}
        	return 0;
        }
}

int get_city_number(string city)
{
	switch(city)
	{
	case "齐国": return 10;
	case "韩国": return 20;
	case "赵国": return 30;
	case "魏国": return 40;
	case "秦国": return 50;
	case "楚国": return 60;
	case "燕国": return 70;
	case "周国": return 80;
	}
	return 1;
}

void set_seller_locate( int p )
{
        SellerLocate = p;    // z * 1000000 + x * 1000 + y
}

int get_seller_locate()
{
        return SellerLocate;
}

// 函数：询问云游商人所在
void do_info(object me, object who)
{
	int z;
	object map;
	string buf;

	if ( SellerLocate == 0 )
		return ;
	z = SellerLocate/ 1000000;
	if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;
        switch(random(3))
        {
        	case 0:
        		buf = "%s:\n    听说云游商人会在%s(%d,%d)逗留一段时间。";
        		break;
        	case 1:
        		buf = "%s:\n    有人见过云游商人在%s(%d,%d)出现过，不知是真是假。";
        		break;
		default:
			buf = "%s:\n    云游商人最近会去%s(%d,%d)行商，应该会停留一段时间。";
        		break;
        }
        buf = sprintf(buf,me->get_name(),map->get_name(),( SellerLocate % 1000000 ) / 1000, SellerLocate % 1000);
        send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),buf);
}

void accept_quest(object player,object master)
{
	int date, type, level, size, p, x, y, z;
	string npc;
	object target,map;
	string *Masters;

	check_date(player);
	type = player->get("master.type");
	if ( !type )
		return ;
	player->delete("master.type");
	player->set_save_2("mastertask.type", type);
	player->set_save_2("mastertask.begintime", time());
	player->set_save_2("mastertask.endtime", time()+3600);
	player->set_save_2("mastertask.status", 0);
	player->set_save_2("mastertask.target",0);

	switch (type)
	{
	default :
		player->set_save_2("mastertask.type", 0);
		return ;
	case 1:
		level = player->get_level();
		player->set_save_2("mastertask.targetname",player->get("master.targetname")[0]);
		player->set_save_2("mastertask.target",player->get("master.targetname")[1]);
		break;
	case 2:
		player->set_save_2("mastertask.targetpic", player->get("master.exp"));
		player->set_save_2("mastertask.targetxy", 0 );
		break;
	case 3:
		player->set_save_2("mastertask.targetpic", player->get("master.pot"));
		player->set_save_2("mastertask.targetxy", 0 );
		break;
	case 4:
	case 5:
	case 7:
		player->delete_save_2("mastertask.targetname");
		player->delete_save_2("mastertask.targetpic");
		player->set_save_2("mastertask.status",0);
		break;
	case 6:
		player->set_save_2("mastertask.targetname",player->get("master.targetname"));
		player->set_save_2("mastertask.targetcity", player->get("master.targetcity"));
		break;
	case 8:
		player->set_save_2("mastertask.targetname",player->get("master.targetname"));
		break;
	case 9:
		z = get_z(master);
		if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;
		target = new ("/npc/task/master_2.c");
		if (!target) return;
		p = player->get("mastertask.targetxy");
		x = p / 1000; y = p % 1000;
		level = player->get_level();
		target->set("level", level);

		target->set_level(level);
		NPC_ENERGY_D->init_level(target, level);
		target->add_max_hp( target->get_max_hp()*2 );
		target->add_dp( target->get_dp()/5*4 );
		target->add_pp( target->get_pp()/2 );
		target->set_walk_speed( 4 );
		target->set_attack_speed( 15 );

		target->set_char_type(FIGHTER_TYPE_2);
		target->set_name(sprintf("狂徒(%d)", player->get_number()) );
		target->set_char_picid(0200);
		target->add_to_scene(z, x, y, 3);
		map->add_reset(target);    // 加入复位列表
		target->set("user", player->get_number());
		player->set_save_2("mastertask.target", sprintf("%x#",getoid(target)));
		player->set_save_2("mastertask.targetxy1", player->get("mastertask.targetxy1"));
		break;
	case 10:
		player->set_save_2("mastertask.targetname",player->get("master.targetname"));
		break;
	case 11:
		player->set_save_2("mastertask.endtime", time()+7200);
		break;
	case 12:
		player->set_save_2("mastertask.targetname",player->get("master.targetname"));
		break;
	case 13:
		player->set_save_2("mastertask.targetname",player->get("master.targetname"));
		break;
	}
	player->add_save_2("mastertask.count", 1);
	send_task_desc(player,1);
}

void task_info(object player,object master)
{
	string name1, name2, result = "";
	int id, status, level, order1, order2,exp,pot,date;
	int type,x,y;
	object item,pet;

        name1 = player->get_fam_name();
        name2 = master->get_fam_name();
        if( name1 == "" || name1 != name2 || player->get_fam_master()!=master->get_name() )
                return;
	id = getoid(master);
	order1 = player->get_fam_order();
	order2 = master->get_fam_order();

	type = player->get_save_2("mastertask.type");
	if ( type == 0 )
		return ;
	status = player->get_save_2("mastertask.status");

	if ( status != 99 )
	{
		if ( type == 1 )
		{
			if ( (pet=USER_BEAST_D->have_beast(player,player->get_save_2("mastertask.targetname"))) )
			{
				if ( player->get("mastertask.finish") )		//抓宠任务完成
				{
					player->delete("mastertask.finish");
					USER_BEAST_D->destruct_pet(player,pet);
					task_bonus(player,master);
					return;
				}
				else
				{
					player->set("mastertask.finish",1);
					send_user( player, "%c%s", ':', sprintf("%s：\n    徒儿办事如此利落，为师能有你这样的徒弟甚感欣慰啊！呵呵……这是为师送给你的，望你以后再接再厉。\n"ESC "完成任务\ntalk %x# task_info\n"ESC"离开", master->get_name(),getoid(master) ) );
					return ;
				}
			}
			else
				result = sprintf( "%s：\n    徒儿，捉到了吗？打开你的技能界面，选择生活一栏，在里面就可以找到一个捕抓宠物的技能，明白了吗？记住，捕抓时候怪物的气血越低捕抓的成功率会越高的。再去试一次吧！为师还是相信你的。\n"ESC "学习技能\ntalk %x# skills\n", master->get_name(), id );

		}
		else if ( type == 2 )
			result = sprintf( "%s：\n    完成我交代的任务了吗？做任务可要讲究方法哦！你有没想过如何在最短的时间内获得最多的经验呢？一定要选择适合自己打怪的地点哦！\n"ESC "学习技能\ntalk %x# skills\n", master->get_name(), id );
		else if ( type == 3 )
			result = sprintf( "%s：\n    你的武学能力提升不是很快哦！是不是没找到适合自己的方法？为师建议你去杀一些妖魔，完成一些任务或者使用一些特定物品。\n"ESC "学习技能\ntalk %x# skills\n", master->get_name(), id );
		else if ( type == 7 )
			result = sprintf( "%s：\n    云游商人四海为家，行踪飘忽不定。要想寻到他本人必须要有耐心，你可以试着向其他玩家打听一下云游商人曾在哪里出现过。\n"ESC "学习技能\ntalk %x# skills\n", master->get_name(), id );
		else if ( type == 9 )
		{
			x = player->get_save_2("mastertask.targetxy1");
			y = x % 1000;
			x = x / 1000;
			if ( status == 2 )
			{
				player->set_save_2("mastertask.status",99);
				result = sprintf( "%s：\n    徒儿做的很好，不教训一下那帮鼠辈，定会被各大门派笑话，如此以来，本门威信何存？\n"ESC "完成任务\ntalk %x# task_info\n", master->get_name(), id );
				send_user( player, "%c%s", ':', result );
				return ;
			}
			else
				result = sprintf( "%s：\n    听本门弟子说，师门附近那些可疑人物还未消失，他们就在师门(%d,%d)附近出现，而且诡计多端，你可以尝试着用天眼或缉捕公文寻找。\n"ESC "学习技能\ntalk %x# skills\n", master->get_name(),x,y,id );

		}
		else if ( type == 10 )
			result = sprintf( "%s：\n    切磋之时要善于发现对方武学之弱点，以己之长攻对方之短。此外，还要随机应变，灵活应用本门武学技巧，以奇制胜。\n"ESC "学习技能\ntalk %x# skills\n", master->get_name(), id );
		else
			result = sprintf( "%s：\n    本门武艺博大精深，具有化腐朽为神奇，夺天地造化之功。小徒你平常需要多努力钻研才好。不知今日找为师有何事干？\n"ESC "学习技能\ntalk %x# skills\n", master->get_name(), id );
		if (order1==order2 && order2!=1) result += sprintf(ESC"挑战\ntalk %x# apprentice.1\n", id);
                result += sprintf(ESC"哪里可以买到本门派的武器？\ntalk %x# apprentice.11\n",getoid(master));
	        result += ESC"向师傅请安\nCLOSE";
		send_user( player, "%c%s", ':', result );
		return;
	}
	switch(type)
	{
	case 9:
	case 10:
		send_user( player, "%c%s", ':', sprintf("%s：\n    徒儿办事如此利落，为师能有你这样的徒弟甚感欣慰啊！呵呵……这是为师送给你的，望你以后再接再厉。", master->get_name() ) );
		break;
	case 7:
		name1 = player->get_save_2("mastertask.targetname");
		if ( stringp(name1) )
		{
			item = present(name1, player, 1, MAX_CARRY*4);
			if ( objectp(item) )
			{
				item->remove_from_user();
				destruct(item);
			}
		}
		send_user( player, "%c%s", ':', sprintf("%s：\n    徒儿办事如此利落，为师能有你这样的徒弟甚感欣慰啊！呵呵……这是为师送给你的，望你以后再接再厉。", master->get_name() ) );
		break;
	case 2:
	case 3:
		send_user( player, "%c%s", ':', sprintf("%s：\n    做的好，看来这次锻炼对你来说还算不错，长了不少见识。", master->get_name() ) );
		break;
//	case 1:
//		player->del_beast(player->get_save_2("mastertask.targetname"));
//		send_user( player, "%c%s", ':', sprintf("%s：\n    徒儿办事如此利落，为师能有你这样的徒弟甚感欣慰啊！呵呵……这是为师送给你的，望你以后再接再厉。", master->get_name() ) );
//		break;
	default:
		return ;
	}
	task_bonus(player,master);
	return ;
}
//司库接受任务
void accept_task9(object player,object npc,string arg)
{
	int i,j,level,size;
	object obj,*inv,*nTask=({}), item;
	string result,*nTmp,*nResult,result1;

	i = player->get_save_2("mastertask.type");
	j = player->get("master.type");
	if ( j!=4&&j!=5&&j!=41&&j!=52&&j!=59 )
		return ;
	player->set("master.type",0);
	i = to_int(arg);
	if ( i == 1 )
	{
		if ( !stringp(result=player->get("master.targetname")) || !stringp(result1=player->get("master.giftname")) )
		{
	        	level = player->get_level();
	        	if ( level < 30 )
	        		j = 1;
	        	else if ( level < 50 )
	        		j = 2;
	        	else if ( level < 70 )
	        		j = 3;
	        	else
	        		j = 4;
	        	if ( j > 1 && random(100) < 40 )
	        		j--;
	        	nResult = "sys/task/quest1"->get_random_siku(j);
	        	result = nResult[0];
	        	result1 = nResult[1];
			player->set("master.targetname",result);
			player->set("master.giftname",result1);
        	}
        	player->set("master.type",41);

        	send_user( player, "%c%s", ':', sprintf("%s：\n由于平时没有细加留意，本门有些物品储备明显不足，如果不抓紧时间解决，将会给本门带来很大麻烦。但此时人手不够，就只好麻烦你去%s处采购%s回来交给我就可以了。回来用给予指令（Alt＋G）交给我就可以了。\n"ESC"接受\ntalk %x# accept_task.11\n"ESC"拒绝\ntalk %x# accept_task.10\n", npc->get_name(),result1,result,getoid(npc),getoid(npc)) );
        	return ;
	}
	if ( i == 2 )
	{
        	level = player->get_level();

        	if ( !stringp(player->get_save_2("mastertask.targetname")) || !stringp(player->get_save_2("mastertask.targetpic")))
        	{
        		nTmp = "sys/task/quest1"->get_random_quest3(level);
			player->set_save_2("mastertask.targetname",nTmp[0]);
			player->set_save_2("mastertask.targetpic",nTmp[1]);
		}
        	player->set("master.type",52);
        	send_user( player, "%c%s", ':', sprintf("%s：\n经过我仔细考虑，觉得有些物品必须收集一部分以做必备之用。曾听师傅说你是他的得意弟子，那就麻烦你去收集带回来吧！据说%s，何不去寻寻看。\n"ESC"接受\ntalk %x# accept_task.21\n"ESC"拒绝\ntalk %x# accept_task.20\n", npc->get_name(), player->get_save_2("mastertask.targetpic"), getoid(npc),getoid(npc)) );
	}
	if ( i == 10 || i == 20 )
	{
		item = player->get_equip(HAND_TYPE);
		if (item && item->get_item_number()==10001078)
		{
                        send_user( player, "%c%c%s", 0x59, 1, sprintf("你是否使用'瞒天过海符'来消除你的任务间隔时间？\n"
                        	ESC "%c\n"ESC"use %x# master2\n"
                                , 1, getoid(item) ) );		
			return;                               		
		}
		clear_task(player,1);
		player->set_save_2("master.questtime",time());
		return ;
	}
	if ( i == 11 )
	{
		if ( !stringp(player->get("master.targetname")) || !stringp(player->get("master.giftname")) )
			return ;
		player->set_save_2("mastertask.status", 1);
		player->set_save_2("mastertask.targetname",player->get("master.targetname"));
		player->set_save_2("mastertask.giftname",player->get("master.giftname"));
		player->delete("master.targetname");
		player->delete("master.giftname");
		player->add_exp(20);
		send_user ( player, "%c%s", ';', "你得到20点经验");
		send_task_desc(player,0);
		return ;
	}
	else if ( i == 21 )
	{
		if ( !stringp(player->get_save_2("mastertask.targetname") ) || !stringp(player->get_save_2("mastertask.targetpic")) )
			return ;
		player->set_save_2("mastertask.status", 1);
		player->set_save_2("mastertask.targetxy",5);
		player->add_exp(20);
		send_task_desc(player,0);
		send_user ( player, "%c%s", ';', "你得到20点经验");
		return ;
	}
	else if ( i == 29 )	//是否完成
	{
	        inv = all_inventory(player, 1, MAX_CARRY*4);
	        size = sizeof(inv);
	        j = 0;
	        for (i=0;i<size;i++)
	        {
	                if (inv[i]->get_name()==player->get_save_2("mastertask.targetname")&& !inv[i]->get_no_give())
	                {
	                        nTask += ({inv[i]});
	                        j+=inv[i]->get_amount();
	                        if ( j >=5 )
	                        	break;
	                }
	        }
	        if ( j < 5 )
	        	return ;
	        j = 5;
	        for(i=0,size=sizeof(nTask);i<size;i++)
	        {
	        	if ( nTask[i]->get_amount() <= j )
	        	{
	        		j -= nTask[i]->get_amount();
                		nTask[i]->remove_from_user();
                		destruct(nTask[i]);
                	}
                	else
                	{
                		nTask[i]->set_amount(nTask[i]->get_amount()-j);
                		j = 0;
                	}
                	if ( j == 0 )
                		break;
	        }
        	task_bonus(player,npc);
	}

}

void task_bonus(object player, object master)
{
	int level,exp,pot,date,time,type,iCash,con,count, gold;
	string result,tmp="",cQue;

	count = player->get_save_2("mastertask.count");
	type = player->get_save_2("mastertask.type");
	if ( type == 0 )
		return ;
	level = player->get_level();
	time = player->get_save_2("mastertask.time")+1;
	switch(time)
	{
		case 5..6:
			con = 1;
			break;
		case 7..8:
			con = 2;
			break;
		case 9..10:
			con = 3;
			break;
	}
	exp = level*8 + time*time*level*4;
	pot = level + 20*time;
	gold = 500 + level*6*(time-1);
	if ( type == 4  )
		iCash = 2000;
	else if ( type == 5 )
		iCash = 2000;
	else if ( type == 11 )
		iCash = 20000;
	else if ( type == 12 )
		iCash = 10000;
	else if ( type == 13 )
		iCash = 15000;
	iCash += gold;
	if ( count > 20 )	//每天次数超过20次奖励减少
	{
		pot = pot * 2 / 5;
		exp = exp * 2 / 5;
		con = 0;
		iCash = iCash * 2 / 5;
	}
	else if ( player->get_vip() )	//vip玩家
	{
		pot = pot * 3 / 2;
		exp = exp * 3 / 2;
		con = con * 3 / 2;
		iCash = iCash * 3 / 2;
	}	
	if (player->get_level()<20) exp = exp * 6 / 10;
	con = con * player->get_online_rate() / 100;
	iCash = iCash * player->get_online_rate() / 100;
	pot = pot * player->get_online_rate() / 100;
	exp = exp * player->get_online_rate() / 100;
	if ( con )
	{
		player->set_fam_contribute(player->get_fam_contribute()+con);
		tmp = sprintf(" 门派贡献点"HIY" %d "NOR"点",con);
	}
	if ( iCash )
	{
		player->add_cash(iCash);
		player->log_money("师门", iCash);
		"/sys/sys/count"->add_income("mastertask", iCash);
		result = sprintf("你完成第" HIY " %d "NOR"个任务，获得金钱"HIY" %d "NOR"经验"HIY" %d "NOR"潜能"HIY" %d "NOR"点%s。", time,iCash, exp, pot,tmp);
	}
	else
		result = sprintf("你完成第" HIY " %d "NOR"个任务，获得经验"HIY" %d "NOR"潜能"HIY" %d "NOR"点%s。", time, exp, pot,tmp);
	send_user ( player, "%c%s", ';', result );
	player->add_exp( exp);
	player->add_potential(pot);
//	if ( time==5 || time==10 )
//		give_five_bonus(player);
	if (time >=10 ) //每10次奖励
	{
		player->set_save_2("mastertask.time", 0);
		if (random100() < player->get_online_rate())
		{
			if ( count <= 20)
				check_random_bonus(player);
			// 奖励宝箱
			if (random100()<5) "/quest/box"->give_box(player);
			// 隐藏任务
			if (random100()<30)
			{
				player->set("m_hide",1);
				cQue = sprintf("    由于你积极完成师傅的嘱托，因此师傅降大任于你（隐藏任务），你是否接受？\n"+ESC"接受\nmaster_hide 0\n"+ESC"拒绝\nmaster_hide 1") ;
				if ( !stringp(cQue) )
					return;
	//			send_user( player, "%c%c%w%s", ':', 3, master->get_char_picid(), cQue);
				send_user( player, "%c%c%s", ':', 3, cQue);
			}
		}
	}
	else
		player->add_save_2("mastertask.time", 1);
	check_date(player);
        player->add_log("$master", iCash);
        player->add_log("&master", exp);
        player->add_log("*master", pot);
        player->add_log("#master", 1);
	clear_task(player,0);
	extra_skill_bonus(player);
	"/sys/sys/count"->add_task("师门", 1);
}
//司库询问任务完成
void task_finish9(object player, object master)
{
	string result ;
	object *inv;
	int i,size,iCount=0,type;

        inv = all_inventory(player, 1, MAX_CARRY*4);
        size = sizeof(inv);
        for (i=0;i<size;i++)
        {
                if (inv[i]->get_name()==player->get_save_2("mastertask.targetname") && !inv[i]->get_no_give())
                {
                        iCount+=inv[i]->get_amount();
                }
        }
	if ( iCount < 5 )
		result = master->get_name() + sprintf(":\n    据说%s，如此才能得到。何不去寻寻看。",player->get_save_2("mastertask.targetpic"));
	else
	{
		player->set("master.type",59);
		result = sprintf("%s：\n    不错，这么快就把东西找回来了。我刚刚也向师傅禀告了你的功劳，这是师傅给你的奖励。\n"
                	ESC"完成任务\ntalk %x# accept_task.29\n"ESC"离开\nclose\n" ,
                master->get_name(),getoid(master) );
	}
	send_user( player, "%c%s", ':', result );

}
//云游商人给予灵药
void accept_task10(object player,object npc,string arg)
{
	object item;
	int p;

	if ( player->get_save_2("mastertask.type") != 7 )
		return ;
	p = to_int(arg);
	if ( p == 1 )
	{
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s\n    本人游历四方，向来是来无影，去无踪。你既然能寻到本人，也算一种缘分，本人就满足你的一个要求。\n"ESC"完成任务\ntalk %x# accept_task.2\n"ESC"离开",npc->get_name(),getoid(npc)));
		return ;
	}
	if ( player->get_save_2("mastertask.status") == 99 )
		return ;
	item = new(sprintf("/item/98/%d",9872+random(7)));
	if ( !objectp(item) )
		return ;
	if( USER_INVENTORY_D->can_carry(player, item)  >=1 )
	{
		p =item->move(player, -1);
		item->add_to_user(p);
	}
	else
	{
		destruct(item);
		notify( "您携带的东西太多了。" );
		return ;
	}
	player->set_save_2("mastertask.targetname",item->get_name());
	player->set_save_2("mastertask.status",99);
	player->add_exp(1000);
	send_user ( player, "%c%s", ';', "你得到1000点经验" );
	send_task_desc(player,1);
}
//连续5次的奖励
void give_five_bonus(object who)
{
	string name,unit;
	int i,j,level,*nTmp;
	object item;
	mapping mpFood = ([
			130 : ({3301,3302}),
			110 : ({3310,3311}),
			90 : ({3303,3304}),
			70 : ({3320,3280}),
			50 : ({3281,3285}),
			30 : ({3283,3284}),
			10 : ({3282,3325}),
		]);

	return ;	//不奖励了

	name = who->get_fam_name();
	level = who->get_level();
	i = who->add_save_2("mastertask.fivebonus",1);
	if ( i > 4 )
		return ;
	if ( i < 1 )
		i = 1;
	if ( name == "昆仑山" || name == "茅山" || name == "云梦泽" )	//酒
	{
		if ( level >= 130 )
			item = new("item/31/3156");
		else if ( level >= 110 )
			item = new("item/31/3155");
		else if ( level >= 90 )
			item = new("item/31/3154");
		else if ( level >= 70 )
			item = new("item/31/3153");
		else if ( level >= 50 )
			item = new("item/31/3152");
		else if ( level >= 30 )
			item = new("item/31/3151");
		else
			item = new("item/31/3150");
	}
	else	//食物
	{
		if ( level >= 130 )
			level = 130;
		else if ( level >= 110 )
			level = 110;
		else if ( level >= 90 )
			level = 90;
		else if ( level >= 70 )
			level = 70;
		else if ( level >= 50 )
			level = 50;
		else if ( level >= 30 )
			level = 30;
		else
			level = 10;
		nTmp = mpFood[level];
		level = nTmp[random(sizeof(nTmp))];
		item = new(sprintf("item/%d/%d",level/100,level));
	}
	if ( !objectp(item) )
		return ;
	item->set_amount(i*4);
	unit = item->get_unit();
	name = item->get_name();
	if( USER_INVENTORY_D->can_carry(who, item)  >=1 )
	{
		j =item->move(who, -1);
		item->add_to_user(j);
		send_user ( who, "%c%s", '!', sprintf("你得到 %s", name) );
	}
	else
	{
		destruct(item);
		notify( "您携带的东西太多了。" );
	}
}
//清除任务变量,发送任务取消信息到客户端
void clear_task(object player,int iCancel)
{
	int type;
	type = player->get_save_2("mastertask.type");
	player->delete_save_2("mastertask.status");
	player->delete_save_2("mastertask.type");
	player->delete_save_2("mastertask.target");
	player->delete_save_2("mastertask.targetxy");
	player->delete_save_2("mastertask.targetxy1");
	player->delete_save_2("mastertask.targetname");
	player->delete_save_2("mastertask.targetpic");
	player->delete_save_2("mastertask.begintime");
	player->delete_save_2("mastertask.endtime");
	player->delete_save_2("master.questtime");
	player->delete_save_2("mastertask.giftname");

	if ( iCancel == 1 )
		player->delete_save_2("mastertask.time");

	clear_task_desc(player,type);

}
//取消任务
void task_giveup(object player)
{
	int date,type,status,i,size,z;
	object obj,map, item;
	string result,*team2;

	check_date(player);
	if ((type=player->get_save_2("mastertask.type"))==0) return;
	// 取消任务必须在三分钟之后
	if (time() - player->get_save_2("mastertask.begintime")<0 ) player->set_save_2("mastertask.begintime", 0);
	if (time() - player->get_save_2("mastertask.begintime")<3*60)
	{
		item = player->get_equip(HAND_TYPE);
		if (item && item->get_item_number()==10001078)
		{
                        send_user( player, "%c%c%s", 0x59, 1, sprintf("你是否使用'瞒天过海符'来消除你的任务间隔时间？\n"
                        	ESC "%c\n"ESC"use %x# master\n"
                                , 1, getoid(item) ) );			
			return;
		}
		send_user( player, "%c%s", '!', "请稍后再取消任务" );
		return;
	}
	status = player->get_save_2("mastertask.status");

	if ( type == 1 || type == 2 || type == 3 || type == 7  )
	{
		if ( status == 99 )
			send_user( player, "%c%s", '!', "任务已经完成了，请向师傅报告。" );
		else
			clear_task(player,1);
	}
	else if ( type == 4 || type == 5 || type == 6)
	{
		clear_task(player,1);
	}
	else if ( type == 8 )
	{
		if ( status == 0 )
			clear_task(player,1);
		else if ( status == 2 || status == 99 )
			send_user( player, "%c%s", '!', sprintf("任务已经完成了，请向%s典狱官报告。",player->get_save_2("mastertask.targetname")) );
		else if ( status == 1 )
		{
			obj = find_char(player->get_save_2("mastertask.target"));
			if ( objectp(obj) && obj->get("user") == player->get_number() )
			{
				obj->remove_from_scene();
				obj->before_destruct();
				destruct(obj);
			}
			clear_task(player,1);
		}
	}
	else if ( type == 9 )
	{
		if ( status == 99 || status == 2 )
			send_user( player, "%c%s", '!', "任务已经完成了，请向师傅报告。" );
		else
		{
			obj = find_char(player->get_save_2("mastertask.target"));
			if ( objectp(obj) && obj->get("user") == player->get_number() )
			{
				obj->remove_from_scene();
				obj->before_destruct();
				destruct(obj);
			}
			clear_task(player,1);
		}
	}
	else if ( type == 10 )
	{
		if ( status == 99 )
			send_user( player, "%c%s", '!', "任务已经完成了，请向师傅报告。" );
		else
		{
			obj = find_char(player->get_save_2("mastertask.target"));
			if ( objectp(obj) && obj->get("user") == player->get_number() )
			{
				z = get_z(obj);
				if ( z == get_z(player) )
				{
					send_user( player, "%c%s", '!', "在这个地方不能取消任务！" );
					return ;
				}
				obj->remove_from_scene();
				obj->before_destruct();
				destruct(obj);
				map = get_map_object(z);
				NEWBIE->destruct_virtual_map(map, z);
			}
			clear_task(player,1);
		}
	}
	else if ( type == 11 )
	{
		if ( status == 0 )
			clear_task(player,1);
		else if ( status == 98 || status == 99 )
			send_user( player, "%c%s", '!', sprintf("任务已经完成了，请向%s报告。","/sys/task/quest1"->get_manager_name(player->get_fam_name())) );
		else if ( status == 1 )
		{
		        obj = present("银票", player, 1, MAX_CARRY*4);
		        if ( objectp(obj) )
		        {
		                obj->remove_from_user();
		                destruct(obj);
		        }
			clear_task(player,1);
		}
	}
	else if ( type == 12 )
	{
		if ( status == 0 )
			clear_task(player,1);
		else if ( status == 4 || status == 98 || status == 99 )
			send_user( player, "%c%s", '!', sprintf("任务已经完成了，请向%s总管报告。",player->get_save_2("mastertask.targetname")) );
		else
		{
			if ( stringp(player->get_save_2("mastertask.target")) )
			{
				team2 = explode(player->get_save_2("mastertask.target"),"|");
				for(i=0,size=sizeof(team2);i<size;i++)
				{
					obj = find_char(team2[i]);
					if ( !objectp(obj) || obj->get("user") != player->get_number() )
						continue;
					obj->remove_from_scene();
					obj->before_destruct();
					destruct(obj);
				}
			}
			clear_task(player,1);
		}
	}
	else if ( type == 13 )
	{
		if ( status == 0 )
			clear_task(player,1);
		else if ( status == 6 || status == 98 || status == 99 )
			send_user( player, "%c%s", '!', sprintf("任务已经完成了，请向%s总管报告。",player->get_save_2("mastertask.targetname")) );
		else
		{
			if ( stringp(player->get_save_2("mastertask.target")) )
			{
				team2 = explode(player->get_save_2("mastertask.target"),"|");
				for(i=0,size=sizeof(team2);i<size;i++)
				{
					obj = find_char(team2[i]);
					if ( !objectp(obj) || obj->get("user") != player->get_number() )
						continue;
					obj->remove_from_scene();
					obj->before_destruct();
					destruct(obj);
				}
			}
			clear_task(player,1);
		}
	}
}

void task_giveup2(object who)
{
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 3,TID_MASTERFIGHT,1,"" );
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTERFIGHT,1,"" );
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_MASTERFIGHT,"" );
	who->delete_save_2("masterfight");
}

//清除任务描述
void clear_task_desc(object who, int type)
{
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 3,TID_MASTER,type,"" );
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,type,"" );
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_MASTER,"" );
}

void send_task_list(object who, int type)
{
	int status ;
	status = who->get_save_2("mastertask.status");
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_MASTER,"师门任务" );
	switch(type)
	{
		case 1:
			if ( status != 99 )
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,1,"抓怪任务" );
			else
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,1,"抓怪任务(已完成)" );
			break;
		case 2:
			if ( status != 99 )
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,2,"历练任务" );
			else
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,2,"历练任务(已完成)" );
			break;
		case 3:
			if ( status != 99 )
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,3,"游历任务" );
			else
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,3,"游历任务(已完成)" );
			break;
		case 4:
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,4,"采购任务" );
			break;
		case 5:
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,5,"收集任务" );
			break;
		case 6:
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,6,"拜访任务" );
			break;
		case 7:
			if ( status != 99 )
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,7,"寻踪任务" );
			else
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,7,"寻踪任务(已完成)" );
			break;
		case 8:
			if ( status != 2 && status != 99 )
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,8,"协助治安任务" );
			else
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,8,"协助治安任务(已完成)" );
			break;
		case 9:
			if ( status != 2 && status != 99 )
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,9,"巡山任务" );
			else
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,9,"巡山任务(已完成)" );
			break;
		case 10:
			if ( status != 99  )
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,10,"门派切磋任务" );
			else
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,10,"门派切磋任务(已完成)" );
			break;
		case 11:
			if ( status != 98 && status != 99 )
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,11,"筹集资金任务" );
			else
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,11,"筹集资金任务(已完成)" );
			break;
		case 12:
			if ( status < 4 )
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,12,"追杀叛徒任务" );
			else
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,12,"追杀叛徒任务(已完成)" );
			break;
		case 13:
			if ( status < 6 )
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,13,"追捕刺客任务" );
			else
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER,13,"追捕刺客任务(已完成)" );
			break;
		}
}

//发送任务详细描述
void send_task_intro(object me)
{
	int type,status,z,x,y, i, size, flag;
	string result,id,name, *team2;
	object who,npc, owner;

	type = me->get_save_2("mastertask.type");
	status = me->get_save_2("mastertask.status");
	result = "任务失败";
	switch(type)
	{
		case 1:
			if (status!=99)
				result = sprintf(BLK"抓怪(第%d轮)\n"BLK"任务目的：\n"BLK"    捕抓一个"HIR"%s"BLK"回来给师傅。\n"BLK"任务描述：\n"BLK"    如今天下世道纷乱不堪，妖魔鬼怪四出肆虐，师傅要我去捉一个回来严加审问。据说%s，何不去寻寻看。如果不知道如何捕抓怪物，打开你的技能界面，选择生活一栏，在里面就可以找到一个捕抓宠物的技能，将这个技能拖曳到快捷栏中对着怪物使用就可以了。",me->get_save_2("mastertask.time")+1,me->get_save_2("mastertask.targetname"),me->get_save_2("mastertask.target"));
			else
				result = sprintf(BLK"抓怪(第%d轮)\n"BLK"任务目的：\n"BLK"    捕抓一个"HIR"%s"BLK"回来给师傅。\n"BLK"%s  1/1\n"BLK"任务描述：\n"BLK"    如今天下世道纷乱不堪，妖魔鬼怪四出肆虐，师傅要我去捉一个回来严加审问。据说%s，何不去寻寻看。如果不知道如何捕抓怪物，打开你的技能界面，选择生活一栏，在里面就可以找到一个捕抓宠物的技能，将这个技能拖曳到快捷栏中对着怪物使用就可以了。",me->get_save_2("mastertask.time")+1,me->get_save_2("mastertask.targetname"),me->get_save_2("mastertask.targetname"),me->get_save_2("mastertask.target"));
			break;
		case 2:
			if (me->get_save_2("mastertask.status")!=99)
				result = sprintf(BLK"历练(第%d轮)\n"BLK"任务目的：\n"BLK"    提升%d点经验值后，回去禀告师傅。\n"BLK"提升经验：  %d/%d\n"BLK"任务描述：\n"BLK"    学艺之人只有勤加练习，技艺才可能日近精湛。如此坚持下去，方可领略到本门武学之精华，看来师傅要你提升%d经验来检验你平时练习的成果。\n", me->get_save_2("mastertask.time")+1,me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetxy"),me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic")    );
			else
				result = sprintf(BLK"历练(第%d轮)\n"BLK"任务目的：\n"BLK"    提升%d点经验值后，回去禀告师傅。\n"BLK"提升经验：  %d/%d\n"BLK"任务描述：\n"BLK"    学艺之人只有勤加练习，技艺才可能日近精湛。如此坚持下去，方可领略到本门武学之精华，看来师傅要你提升%d经验来检验你平时练习的成果。\n", me->get_save_2("mastertask.time")+1,me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic")    );
			break;
		case 3:
			if (me->get_save_2("mastertask.status")!=99)
				result = sprintf(BLK"游历(第%d轮)\n"BLK"任务目的：\n"BLK"    提升%d点潜能后，回去禀告师傅。\n"BLK"提升潜能：  %d/%d\n"BLK"任务描述：\n"BLK"    想学到更上乘的武学精要，能力显得极为重要，能力只有在实践中磨练出来。师傅希望我出去走一走，去磨练一下，以此来提高我的武学能力。\n", me->get_save_2("mastertask.time")+1,me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetxy"),me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic")    );
			else
				result = sprintf(BLK"游历(第%d轮)\n"BLK"任务目的：\n"BLK"    提升%d点潜能后，回去禀告师傅。\n"BLK"提升潜能：  %d/%d\n"BLK"任务描述：\n"BLK"    想学到更上乘的武学精要，能力显得极为重要，能力只有在实践中磨练出来。师傅希望我出去走一走，去磨练一下，以此来提高我的武学能力。\n", me->get_save_2("mastertask.time")+1, me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic")    );
			break;
		case 4:
			if (me->get_save_2("mastertask.status")==0)
				result = sprintf(BLK"采购(第%d轮)\n"BLK"任务目的：\n"BLK"    去找%s问问，看看能有什么可以帮忙的地方。\n"BLK"任务描述：\n:"BLK"    %s最近禀报说本门部分物品储备不足，急需出门去采购一部分物品回来。师傅让我去找%s问明情况，看能不能帮上忙。\n",
					me->get_save_2("mastertask.time")+1, name ="/sys/task/quest1"->get_manager_name(me->get_fam_name()),name,name );
			else
				result = sprintf(BLK"采购(第%d轮)\n"BLK"任务目的：\n"BLK"    采购1%s，并交给%s。\n"BLK"任务描述：\n"BLK"    %s最近回报说门里部分物品储备不足，过去问问，看看有什么能帮上忙的地方。\n"BLK"    由于平时没有细加留意，本门有些物品储备明显不足，如果不抓紧时间解决，将会给本门带来很大麻烦。但此时人手不够，%s托我去%s采购%s回来交给他。交给他时候用给予指令就可以了（Alt＋G）。\n",
					me->get_save_2("mastertask.time")+1, me->get_save_2("mastertask.targetname"),name ="/sys/task/quest1"->get_manager_name(me->get_fam_name()),name,name, me->get_save_2("mastertask.giftname"), me->get_save_2("mastertask.targetname")  );
			break;
		case 5:
			if (me->get_save_2("mastertask.status")==0)
				result = sprintf(BLK"收集(第%d轮)\n"BLK"任务目的：\n"BLK"    去找%s问问，看看能有什么可以帮忙的地方。\n"BLK"任务描述：\n"BLK"    %s最近向师傅禀报说本门需要部分物品以做必备之用，师傅让我过去询问一下具体情况，看看有什么能帮忙的地方。\n",
					me->get_save_2("mastertask.time")+1, name ="/sys/task/quest1"->get_manager_name(me->get_fam_name()),name );
			else
				result = sprintf(BLK"收集(第%d轮)\n"BLK"任务目的：\n"BLK"    收集五个%s，并交给%s。\n"BLK"任务描述：\n"BLK"    %s最近向师傅禀报说本门需要部分物品以做必备之用，师傅让我过去询问一下具体情况，看看有什么能帮上忙的地方。\n"BLK"    当我找到%s后，他向我说明有些物品必须收集一部分以做必备之用，因而委托我帮忙收集%s回来。据说%s，何不去寻寻看。\n",
					me->get_save_2("mastertask.time")+1, me->get_save_2("mastertask.targetname") ,name ="/sys/task/quest1"->get_manager_name(me->get_fam_name()),name,name,me->get_save_2("mastertask.targetname"),me->get_save_2("mastertask.targetpic")  );
			break;
		case 6:
			result = sprintf(BLK"拜访(第%d轮)\n"BLK"任务目的：\n"BLK"    拜访%s\n"BLK"任务描述：\n"BLK"    师傅闭关修行有些时日了，也不知师傅的老友们近况如何。想当初他们常来探访师傅，如果师傅不去拜访一下未免有些失礼。因而，师傅让我替他老人家问候一下%s的%s。",me->get_save_2("mastertask.time")+1,me->get_save_2("mastertask.targetname"),me->get_save_2("mastertask.targetcity"),me->get_save_2("mastertask.targetname"));
			break;
		case 7:
			if (me->get_save_2("mastertask.status")==99)
				result = sprintf(BLK"寻踪(第%d轮)\n"BLK"任务目的：\n"BLK"  寻踪云游商人\n"BLK"灵药：1/1\n"BLK"任务描述：\n"BLK"    云游商人游历四方，行踪飘忽不定，我既然能寻到他本人也真算是一种缘分。如今云游商人答应了我的要求，给了我灵药，我得尽快将灵药交给师傅，免得他老人家着急。",
				me->get_save_2("mastertask.time")+1);
			else
				result = sprintf(BLK"寻踪(第%d轮)\n"BLK"任务目的：\n"BLK"    寻找云游商人\n"BLK"任务描述：\n"BLK"    师傅最近想尝试炼制一种丹药，但炼制这种丹药须得一种灵药做药引，据说只有传闻中的云游商人才有此种灵药。师傅让我试着去寻找云游商人，如若找到就向他求得此种灵药！\n",
					me->get_save_2("mastertask.time")+1);
			break;
		case 8:
			status = me->get_save_2("mastertask.status");
			x = me->get_save_2("mastertask.targetxy1");
			y = x % 1000;
			x = x / 1000;
			if ( status == 2 || status == 99 )
				result = sprintf(BLK"协助治安(第%d轮)\n"BLK"任务目的：\n"BLK"    消灭城外造谣闹事的流氓。\n"BLK"造谣的混混：1/1\n"BLK"任务描述：\n"BLK"%s的典狱官近日来信要求我们去协助其维持治安，家师命我全力以赴去协助其解决问题。\n"BLK"    当我来到%s后，听城里的典狱官说城外有人在造谣生事。我最好还是亲自过去处理一下。那小贼应该就在（%d，%d）一带出没。",
					me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.targetname"),name,x,y);
			else if ( status == 0 )
				result = sprintf(BLK"协助治安(第%d轮)\n"BLK"任务目的：\n"BLK"    找%s典狱官协助其维持治安。\n"BLK"任务描述：\n"BLK"    %s的典狱官近日来信，说%s内的治安形势越发严峻，请求家师派几名得力弟子前去协助其维持治安。刚好家师就看见我，命我去协助其解决治安混乱问题。\n",
					me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.targetname"),name,name);
			else if( stringp( id = me->get_save_2("mastertask.target") ) && ( npc = find_char(id) ) && npc->get("user")==me->get_number() )
				result = sprintf(BLK"协助治安(第%d轮)\n"BLK"任务目的：\n"BLK"    消灭城外造谣闹事的流氓。\n"BLK"造谣的混混：0/1"HIR"（限时60分钟）"BLK"\n"BLK"任务描述：\n"BLK"%s的典狱官近日来信要求我们去协助其维持治安，家师命我全力以赴去协助其解决问题。\n"BLK"    当我来到%s后，听城里的典狱官说城外有人在造谣生事。我最好还是亲自过去处理一下。那小贼应该就在（%d，%d）一带出没。",
					me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.targetname"),name,x,y);
			else
				result = sprintf(BLK"协助治安(第%d轮)\n"BLK"任务目的：\n"BLK"    消灭城外造谣闹事的流氓。\n"BLK"造谣的混混：0/1"HIR"（任务失败）"BLK"\n",
					me->get_save_2("mastertask.time")+1 );
			break;
		case 9:
			x = me->get_save_2("mastertask.targetxy1");
			y = x % 1000;
			x = x / 1000;
			if ((status=me->get_save_2("mastertask.status"))==99 || status == 2)
				result = sprintf(BLK"巡山(第%d轮)\n"BLK"任务目的：\n"BLK"    在本门派一带巡查，扫除一切可疑的人物。\n"BLK"可疑的人物：1/1\n"BLK"任务描述：\n"BLK"    有弟子禀报师傅说在师门(%d,%d)附近出现了可疑人物，为师命我前去察看一下，如果被我发现是些鸡鸣狗盗之类，定要好好惩治一下他们，否则本门威信何在？\n",
					me->get_save_2("mastertask.time")+1,x,y  );
			else if( stringp( id = me->get_save_2("mastertask.target") ) && ( npc = find_char(id) ) && npc->get("user")==me->get_number() )
				result = sprintf(BLK"巡山(第%d轮)\n"BLK"任务目的：\n"BLK"    在本门派一带巡查，扫除一切可疑的人物。\n"BLK"可疑的人物：0/1"HIR"（限时60分钟）"BLK"\n"BLK"任务描述：\n"BLK"    有弟子禀报师傅说在师门(%d,%d)附近出现了可疑人物，为师命我前去察看一下，如果被我发现是些鸡鸣狗盗之类，定要好好惩治一下他们，否则本门威信何在？\n",
					me->get_save_2("mastertask.time")+1,x,y  );
			else	
				result = sprintf(BLK"巡山(第%d轮)\n"BLK"任务目的：\n"BLK"    在本门派一带巡查，扫除一切可疑的人物。\n"BLK"可疑的人物：0/1"HIR"（任务失败）"BLK"\n",
					me->get_save_2("mastertask.time")+1  );							
			break;
		case 10:
			if ( me->get_save_2("mastertask.status")==99 )
				result = sprintf(BLK"门派切磋(第%d轮)\n"BLK"任务目的：\n"BLK"    去%s门派切磋武艺。\n"BLK"%s弟子：1/1\n"BLK"任务描述：\n"BLK"    %s掌门差人来信邀请本门弟子去其处切磋武艺，以此来弥补各自武学之缺陷。师傅命我前去，此等机会，我可不能错失了，时间有限，我得马上赶过去\n",
					me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.targetname"),name,name  );
			else
				result = sprintf(BLK"门派切磋(第%d轮)\n"BLK"任务目的：\n"BLK"    去%s门派切磋武艺。\n"BLK"%s弟子：0/1\n"BLK"任务描述：\n"BLK"    %s掌门差人来信邀请本门弟子去其处切磋武艺，以此来弥补各自武学之缺陷。师傅命我前去，此等机会，我可不能错失了，时间有限，我得马上赶过去\n",
					me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.targetname"),name,name  );
			break;
		case 11:
			status = me->get_save_2("mastertask.status");
			if (status==0)
				result = sprintf(BLK"筹集资金(第%d轮)\n"BLK"任务目的：\n"BLK"    去找%s问问，帮助他解决问题。\n"BLK"任务描述：\n"BLK"    最近%s好像经常心神不定，看来是有什么烦恼。过去问问，看看可有帮得上忙的地方。\n",
					me->get_save_2("mastertask.time")+1, name="/sys/task/quest1"->get_manager_name(me->get_fam_name()),name );
			else
				result = sprintf(BLK"筹集资金(第%d轮)\n"BLK"任务目的：\n"BLK"    赚取%d贯后，带回给司库。\n"BLK"任务描述：\n"BLK"    最近%s好像经常心神不定，好象是为本门资金而烦恼。过去问问，看看能有可以帮得上忙的地方。\n"BLK"    与%s聊过后，才知道门派的金库已经所剩无几。在%s强大的威迫之下，也只好硬着头皮带着五万金额的银票下山做点小生意了。\n",
					me->get_save_2("mastertask.time")+1, me->get_save_2("mastertask.targetxy"), name="/sys/task/quest1"->get_manager_name(me->get_fam_name()),name,name );
			break;
		case 12:
			status = me->get_save_2("mastertask.status");
			flag = 0;
			if (status!=0 && status<4)
			{
				team2 = explode(me->get_save_2("mastertask.target"),"|");
				
				for(i=0,size=sizeof(team2);i<size;i++)
				{
					owner = find_char(team2[i]);
					if ( !objectp(owner) || owner == me )
						continue;
					if (owner->get("user")!=me->get_number()) continue;
					flag ++;				
				}	
			}						
			if (status==0)
				result = sprintf(BLK"追杀叛徒(第%d轮)\n"BLK"任务目的：\n"BLK"    速去%s找王府总管，帮助其解决困难。\n"BLK"任务描述：\n"BLK"    师傅刚刚收到了一封来自%s王府总管的紧急求助信，看来是发生了什么大事。在师傅的命令下，我整装前往%s。\n",
					me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.targetname"),name,name );
			else
			if (flag==0 && status<4)
				result = sprintf(BLK"追杀叛徒(第%d轮)\n"BLK"任务目的：\n"BLK"  追杀%s的%s\n"BLK"%s    0/1"HIR"（任务失败）"BLK"\n",
					me->get_save_2("mastertask.time")+1, id=me->get_save_2("mastertask.targetname"), name=me->get_save_2("mastertask.targetpic"), name );
			else			
			if (status<4)
				result = sprintf(BLK"追杀叛徒(第%d轮)\n"BLK"任务目的：\n"BLK"  追杀%s的%s\n"BLK"%s    0/1"HIR"（限时60分钟）"BLK"\n"BLK"任务描述：\n"BLK"    师傅刚刚收到了一封来自%s王府总管的紧急求助信，看来是发生了什么大事。在师傅的命令下，我整装往%s出发。\n"BLK"    与%s总管见面之后，我也了解到了事态的严重性。对于叛国之徒是绝对不能轻饶的！\n"BLK"    %s总管的手下已经送来了确切信报，%s正在"HIR"%s(%d,%d)"BLK"一带逃窜。而且%s买通了那一带的山贼流氓做他的贴身保镖。\n"BLK"    为了%s的机密不被泄漏出去，权宜之计只有杀了他。\n",
					me->get_save_2("mastertask.time")+1,id=me->get_save_2("mastertask.targetname"), name=me->get_save_2("mastertask.targetpic"),name,id,id,id,id,name,me->get_save_2("mastertask.giftname"),((z=me->get_save_2("mastertask.targetxy1"))/1000),z%1000,name,id);
			else
				result = sprintf(BLK"追杀叛徒(第%d轮)（已完成）\n"BLK"任务目的：\n"BLK"  追杀%s的叛徒%s\n"BLK"%s    1/1\n"BLK"任务描述：\n"BLK"    师傅刚刚收到了一封来自%s王府总管的紧急求助信，看来是发生了什么大事。在师傅的命令下，我整装往%s出发。\n"BLK"    与%s总管见面之后，我也了解到了事态的严重性。对于叛国之徒是绝对不能轻饶的！\n"BLK"    %s总管的手下已经送来了确切信报，%s正在"HIR"%s(%d,%d)"BLK"一带逃窜。而且%s买通了那一带的山贼流氓做他的贴身保镖。\n"BLK"    为了%s的机密不被泄漏出去，权宜之计只有杀了他。\n",
					me->get_save_2("mastertask.time")+1,id=me->get_save_2("mastertask.targetname"), name=me->get_save_2("mastertask.targetpic"),name,id,id,id,id,name,me->get_save_2("mastertask.giftname"),((z=me->get_save_2("mastertask.targetxy1"))/1000),z%1000,name,id);
			break;
		default:
			status = me->get_save_2("mastertask.status");
			flag = 0;
			if (status!=0 && status<6)
			{
				team2 = explode(me->get_save_2("mastertask.target"),"|");
				
				for(i=0,size=sizeof(team2);i<size;i++)
				{
					owner = find_char(team2[i]);
					if ( !objectp(owner) || owner == me )
						continue;
					if (owner->get("user")!=me->get_number()) continue;
					flag ++;				
				}	
			}			
			if (status==0)
				result = sprintf(BLK"追捕刺客(第%d轮)\n"BLK"任务目的：\n"BLK"    去%s找到王府总管，并听从其命令协助追捕刺客。\n"BLK"任务描述：\n"BLK"    师傅刚刚收到了一封来自%s王府总管的来信，信中说昨晚有刺客潜入了王府企图行刺王爷。尽管最后暗杀失败，王爷也没受伤，但刺客却逃掉了。总管希望我们协助他抓拿刺客，以免后患。\n",
					me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.targetname"),name);
			else
			if (status<6 && flag==0)
				result = sprintf(BLK"追捕刺客(第%d轮)\n"BLK"任务目的：\n"BLK"    追捕已经逃窜到%s的蒙面刺客。"HIR"（限时60分钟）"BLK"\n"BLK"刺客首领	%d/1\n"BLK"蒙面刺客	%d/4\n"HIR"（任务失败）\n"BLK"任务描述：\n"BLK"    师傅刚刚收到了一封来自%s王府总管的来信，信中说昨晚有刺客潜入了王府企图行刺王爷。尽管最后暗杀失败，王爷也没受伤，但刺客却逃掉了。总管希望我们协助他抓拿刺客，以免后患。\n"BLK"    来到%s后，得知行刺者已经逃窜到%s后便失去了踪影。总管大人相信他们仍潜藏在%s一带。\n"BLK"    大人已经颁发了追杀令，一旦发现目标，格杀无论！\n",
					me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.giftname"),me->get_save_2("mastertask.y"),me->get_save_2("mastertask.x"),id=me->get_save_2("mastertask.targetname"),id,name,name);
			else			
				result = sprintf(BLK"追捕刺客(第%d轮)\n"BLK"任务目的：\n"BLK"    追捕已经逃窜到%s的蒙面刺客。\n"BLK"刺客首领	%d/1\n"BLK"蒙面刺客	%d/4\n"HIR"（限时60分钟）\n"BLK"任务描述：\n"BLK"    师傅刚刚收到了一封来自%s王府总管的来信，信中说昨晚有刺客潜入了王府企图行刺王爷。尽管最后暗杀失败，王爷也没受伤，但刺客却逃掉了。总管希望我们协助他抓拿刺客，以免后患。\n"BLK"    来到%s后，得知行刺者已经逃窜到%s后便失去了踪影。总管大人相信他们仍潜藏在%s一带。\n"BLK"    大人已经颁发了追杀令，一旦发现目标，格杀无论！\n",
					me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.giftname"),me->get_save_2("mastertask.y"),me->get_save_2("mastertask.x"),id=me->get_save_2("mastertask.targetname"),id,name,name);
	//				else
	//					result = sprintf("师门任务\n"BLK"追捕刺客(第%d轮)\n"BLK"任务目的：\n"BLK"    追捕已经逃窜到%s的蒙面刺客。\n"BLK"刺客首领	1/1\n"BLK"蒙面刺客	4/4\n"BLK"任务描述：\n"BLK"    师傅刚刚收到了一封来自%s王府总管的来信，信中说昨晚有刺客潜入了王府企图行刺王爷。尽管最后暗杀失败，王爷也没受伤，但刺客却逃掉了。总管希望我们协助他抓拿刺客，以免后患。\n"BLK"    来到%s后，得知行刺者已经逃窜到%s后便失去了踪影。总管大人相信他们仍潜藏在%s。\n"BLK"    大人已经颁发了追杀令，一旦发现目标，格杀无论！\n",
	//						me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.giftname"),id=me->get_save_2("mastertask.targetname"),id,name,name);
			break;
		}
	if ( stringp(result) )
		send_user( me, "%c%c%c%w%w%s", 0x51, 1, 3,TID_MASTER,type,result );
}

//发送任务详细描述
void send_task_intro2(object me)
{
	int type,status,z,x,y;
	string result,id,name;
	object who,npc;
	status = me->get_save_2("masterfight.status");
	if (status==0) return;
	result = BLK"师门挑战\n"BLK"任务目的：\n"BLK"    打赢师叔，获得拜下一级师父的权力。\n";
	send_user( me, "%c%c%c%w%w%s", 0x51, 1, 3,TID_MASTERFIGHT,1,result );
}

//发送任务描述
void send_task_desc(object who,int iFlag)
{
	int type;

	if ( (type=who->get_save_2("mastertask.type")) == 0 )
		return ;
	if ( iFlag == 0 )
	{
		send_task_intro(who);
		return ;
	}
	if ( iFlag == 1 )
		clear_task_desc(who,type);
	send_task_list(who,type);
	send_task_intro(who);
}

void do_init_gift(object who, object npc,string arg)
{
	int i;
	i = to_int(arg);
	if ( i == 1 )
	{
		send_user(who,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf(npc->get_name()+":\n在本长老这免费洗点后，暂时没有其他洗点的途径了，你确定你现在要洗点吗？\n"ESC"确定\ntalk %x# init.2\n"ESC"离开",getoid(npc)));
	}
	if ( i == 2 )
	{
		if ( who->get_save_2("init_gift7") )
			return ;
		who->set_save_2("init_gift7",1);
		"/cmd/user/gift"->init_gift_point(who);
		who->log_legend(sprintf("您在%s处洗属性点。",npc->get_name()));
		send_user(who,"%c%s",'!',"洗点成功!");
	}
}
// 函数：消除之前处理
void before_destruct()
{
	"npc/00/0008"->set("SellerLocate",SellerLocate);
}

void create()
{
	SellerLocate = "npc/00/0008"->get("SellerLocate");
}
//额外提升10级以下的技能
void extra_skill_bonus(object who)
{
	int *nSkill,i,size,*nTmp;
	string cSkill;

	if ( MAIN_D->get_host_type() == 2 )	//台湾除外
		return ;
	if ( random100() >= who->get_online_rate() )
		return ;
	nSkill = mpSkill[who->get_fam_name()];
	nTmp = ({});
	for(i=0,size=sizeof(nSkill);i<size;i++)
	{
		if ( who->get_skill(nSkill[i]) < 10 )
			nTmp += ({nSkill[i]});
	}
	size = sizeof(nTmp);
	if ( size )
	{
		i = nTmp[random(size)];
		who->set_skill(i,who->get_skill(i)+1);
		cSkill = SKILL->get_skill_file(i);
		send_user(who,"%c%s",'!',sprintf("你成功完成了师傅的嘱托，因此你获得了"HIR"%s"NOR"成长一级的奖励！",cSkill->get_name()));
	}
}

//接受师门隐藏任务
void hide_quest(object me)
{
	int z,x,y,p,iTime,level;
	string cName;
	object npc,map;
	if (me->get("m_hide")!=1) return;
	me->delete("m_hide");
        if( !( p = XY_D->get_city_point( -1, IS_CHAR_BLOCK ) ) ) return;
        z = p / 1000000;  x = ( p % 1000000 ) / 1000;  y = p % 1000;
        if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;
//	level = who->get_level() > user->get_level() ?  who->get_level() : user->get_level();
	level = me->get_level();
	iTime = time();
	npc = new("npc/task/8400");
	if ( !npc )
		return ;
	cName = "挑衅人" + NPC_NAME_D->get_banditi_name();
	npc->set_name( cName );
	npc->set("hide1",me->get_number());
//	npc->set("hide2",user->get_number());
	NPC_ENERGY_D->init_level(npc, level);
	init_npc(npc);
	npc->set_max_seek(8);
	map->add_reset(npc); 
	
	npc->add_to_scene(z,x,y);
	npc->set("user", me->get_number());	
	me->delete_save_2("master_hide");
	me->set_save_2("master_hide.npcid",getoid(npc));
	me->set_save_2("master_hide.name",cName);
	me->set_save_2("master_hide.country",map->get_name());
	me->set_save_2("master_hide.x",x);
	me->set_save_2("master_hide.y",y);
	me->set_save_2("master_hide.x1",x+random(20));
	me->set_save_2("master_hide.y1",y+random(20));
	me->set_save_2("master_hide.time",iTime);
	me->set_save_2("master_hide.exp",level*level*20);
	me->set_save_2("master_hide.potential",level*level+level*100);
	send_user( me, "%c%c%c%w%s", 0x51, 1, 1,TID_MASTER_HIDE,"师门任务" ); 
	send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER_HIDE,1,"隐藏任务" ); 

}

//师门隐藏任务怪
void init_npc(object npc)
{
	int p,level;
	
	level = npc->get_level();
	p = random(100);
	if ( p < 20)	//低物防高敏型
	{
		npc->set_skill(348,level);
		npc->set_skill(251,level);
		npc->set_skill(241,level);
		npc->set_char_picid(8011);
                npc->set_walk_speed(4);
                npc->set_attack_speed(10);	
                npc->add_dp(-1*npc->get_dp()/4);
                npc->add_max_hp(npc->get_max_hp()*8);	
                npc->add_sp(npc->get_sp()*2);
                npc->add_ap(npc->get_ap()*4/5);
                npc->add_mp(npc->get_mp()/2);  
                npc->set("hide.type",1);              		
	}
	else if ( p < 40 )	//高物防低法防型
	{
		npc->set_skill(221,level);
		npc->set_skill(231,level);
		npc->set_char_picid(0252);
                npc->set_walk_speed(4);
                npc->set_attack_speed(10);	
                npc->add_dp(npc->get_dp()*3);
                npc->add_max_hp(npc->get_max_hp()*4); 	
                npc->add_pp(-1*npc->get_pp()*3/10);                
                npc->add_ap(npc->get_ap()*4/5);                
                npc->add_mp(npc->get_mp()/2);  
                npc->set("hide.type",2);              		
	}
	else if ( p < 60 )	//高法防低物防型
	{
		npc->set_skill(423,level);
		npc->set_skill(424,level);
		npc->set_skill(425,level);
		npc->set_char_picid(8010);
                npc->set_walk_speed(4);
                npc->set_attack_speed(10);	
                npc->add_dp(-1*npc->get_dp()/4);
                npc->add_max_hp(npc->get_max_hp()*4); 	
                npc->add_sp(npc->get_sp());  
                npc->add_pp(npc->get_pp()*3/2);                
                npc->add_cp(npc->get_cp());
		npc->add_mp(npc->get_mp()*6);
                npc->set("hide.type",3);              		
	}	
	else if ( p < 70 )	//长血型：拳脚类
	{
		npc->set_skill(211,level);
		npc->set_skill(317,level);
		npc->set_char_picid(8000);
                npc->set_walk_speed(4);
                npc->set_attack_speed(10);	
                npc->add_dp(-1*npc->get_dp()/5);        
                npc->add_max_hp(npc->get_max_hp()*20); 
                npc->add_pp(-1*npc->get_pp()/5);                
                npc->add_mp(npc->get_mp()/2);                 
                npc->add_ap(npc->get_ap()*9/10);  
                npc->set("hide.type",4);              		
	}
	else if ( p < 90 )	//长血高物防高法防型：远程暗器类
	{
		npc->set_skill(261,level);
		npc->set_char_picid(8012);
                npc->set_walk_speed(4);
                npc->set_attack_speed(10);	
		npc->add_dp(npc->get_dp()*9/20);
		npc->add_max_hp(npc->get_max_hp()*5); 
 		npc->add_sp(npc->get_sp()*3);
 		npc->add_pp(npc->get_pp()*9/5);
 		npc->add_mp(npc->get_mp());
 		npc->add_ap(npc->get_ap()/2);
                npc->set("hide.type",5);              		
	}
	else 	//强攻型加召唤
	{
		npc->set_skill(414,level);
		npc->set_char_picid(8013);
                npc->set_walk_speed(4);
                npc->set_attack_speed(8);	
                npc->add_dp(npc->get_dp()*9/20);
                npc->add_ap(npc->get_ap()); 
                npc->add_max_hp(npc->get_max_hp()*5);                 
                npc->add_sp(npc->get_sp()*3);  
                npc->add_pp(npc->get_pp()*9/20);      
                npc->add_mp(npc->get_mp()*3/2);  
                npc->set("hide.type",6);              		
	}	
}

//师门隐藏任务玩家死亡处理
void hide_task_die(object who)
{
	int *men_pai = ({289,273,80,324,269,54,165});
	int *shi_fu = ({039070,218169,226052,109165,276192,102144,091033,112083,205174,196031,134143,273195,091140,087030,047063,223163,169064,077129,279189,110152,097035,080054,205158,185074,092117,266183,111137,103026,});
	int aa,bb,x,y,z;
	aa=who->get_fam_type()-1;
	bb=who->get_fam_order()-1;
	z=men_pai[aa];
	x=shi_fu[bb*7+aa]/1000+random(3);
	y=shi_fu[bb*7+aa]%1000+random(3);
        who->add_to_scene(z, x, y, 3);
        send_user(who,"%c%s",'!',"你被挑衅人打败了");
}

//取消师门隐藏任务
master_hide_giveup(object who,object npc)
{
	if ( objectp(npc=find_char(sprintf("%x#",who->get_save_2("master_hide.npcid")))) && npc->is_master_hide_task() )
	{
		npc->remove_from_scene();
		destruct(npc);	
	}
	who->delete_save_2("master_hide");
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_MASTER_HIDE,"" ); 
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_MASTER_HIDE,1,"" ); 
}
