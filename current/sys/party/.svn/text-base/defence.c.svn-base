/*****劫宝飞贼大搜捕****/

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>
#include <action.h>
#include <map.h>

#define MAX_DEFENCE	77

mapping DefenceMap = ([ ]);	// 所有皇城保卫战的地图

int defencecount;			// 生成的计数，免得临时重开新地图时的判断
int endcount;				// 战争完成的计数
int War;				// 战争时间的计数
int State;				// 战争状态 0: 未开放 1 可以进场
void start_defence();
void end_defence();

// 函数：生成二进制码
void SAVE_BINARY() { }
// 函数：构造处理
void create()
{
	call_out("check_time",1);
}

int get_end_count()
{
	return endcount;
}

int set_end_count(int flag)
{
	return endcount = flag;
}

int add_end_count(int flag)
{
	return set_end_count( endcount + flag);
}

int get_count()
{
	return defencecount;
}

int set_count(int flag)
{
	return defencecount = flag;
}

int get_state()
{
	return State;
}

int set_state(int flag)
{
	return State = flag;
}

object * get_city_war(int z)
{
	z /= 10;
	if (sizeof(DefenceMap[z])==0) return ({ });
	return DefenceMap[z];
}

void check_time()
{
	int iTime,rate,level,z,p,x,y;
	int i,*nScene,size;
	mixed *mixTime;
	object robber;

	remove_call_out("check_time");
	if (MAIN_D->get_host_type()==6012) return;
	call_out("check_time", 60);
	iTime = time();
	mixTime = localtime(iTime);	
	if ("/sys/sys/count"->get_war_flag1()<=0 && get_state()==0)
	{
		return;
	}
	if (War==0)
	{
		if ( mixTime[TIME_WDAY] != 6 )
		{
			return ;
		}
		if ( mixTime[TIME_HOUR] == 20 && mixTime[TIME_MIN]== 20 )
		{
			start_defence();
		}
		return;
	}
	War++;
	if (War==11)
	{
		CHAT_D->sys_channel(0,HIY"来自异界的妖魔已经大举入侵各国城都，现"HIR"七国的大将军"HIY"处已经展开紧急的募兵行动，请志愿的勇士速速到将军处集合，加入征讨妖魔的大军！");
	}
	else
	if (War%11==0) CHAT_D->sys_channel(0,HIY"来自异界的妖魔已经大举入侵各国城都，现"HIR"七国的大将军"HIY"处已经展开紧急的募兵行动，请志愿的勇士速速到将军处集合，加入征讨妖魔的大军！");
	if (get_end_count()>=MAX_DEFENCE)
	{
		War=0;
		set_state(0);
	}
}

void start_defence()
{
	object map;
	int i, j, z, p;
	end_defence();
	War = 1;
	set_state(1);
	set_end_count(0);
	set_count(get_count()+1);
	CHAT_D->sys_channel(0,HIY"听说来自异界的妖魔正蠢蠢欲动，计划在"HIR"10分钟后"HIY"攻击各国皇城。现"HIR"各国大将军"HIY"处已经开始紧急募兵行动，请志愿者速到各国将军处报名，加入皇城的保卫战吧！");
	DefenceMap[1] = ({ });
	DefenceMap[2] = ({ });
	DefenceMap[3] = ({ });
	DefenceMap[4] = ({ });
	DefenceMap[5] = ({ });
	DefenceMap[6] = ({ });
	DefenceMap[7] = ({ });
	// 初始化七个国家共77张地图
	for (i=0;i<4;i++)
	{
		for (j=1;j<=7;j++)
		{
			if( ( z = find_map_flag(NEWBIE_MAP_BEGIN, NEWBIE_MAP_END, 0) ) > 0 )
			{
				p = 886;
				init_virtual_map(z, p);    // 生成虚拟地图
				map = new ("/inh/std/defence");
				map->set_client_id(p);
				set_map_object( map, map->set_id(z) );
				map->set_level(i, j);
				map->init_place(map);
				DefenceMap[j] += ({ map });
			}
		}
	}
}

void end_defence()
{
	object * all, map;
	int i, size;
	all = ({ });
	for (i=1;i<=7;i++)
	{
		if (DefenceMap[i]!=0) all += DefenceMap[i];
	}
	all -= ({ 0 });
	size = sizeof(all);
	for (i=0;i<size;i++)
	{
		if (map = all[i])
		{
			map->before_destruct();
		}
	}
	DefenceMap[1] = ({ });
	DefenceMap[2] = ({ });
	DefenceMap[3] = ({ });
	DefenceMap[4] = ({ });
	DefenceMap[5] = ({ });
	DefenceMap[6] = ({ });
	DefenceMap[7] = ({ });	
	set_state(0);
}

void do_defence(object me, object who, string arg)
{
	int flag, id, z, i, size, begin, end, p, x, y;
	string result, name;
	object * all;
	flag = to_int(arg);
	id = getoid(who);
	z = get_z(who);
	switch(flag)
	{
	case 1:
		result = sprintf("%s\n    据探子回报，最近皇城周围都聚集了不少妖魔鬼怪，看来本城即将受到一场前所未有的浩劫！见少侠英气逼人，想必武功必定高强。敢问大侠是否愿意加入我们的军队，共同抵抗妖魔的侵略呢？\n", who->get_name());
		result += sprintf(ESC"了解活动规则\ntalk %x# defence.2\n",id);
		result += sprintf(ESC HIY "参与保卫战\ntalk %x# defence.10\n",id);
		result += ESC"离开";
		send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
		break;
	case 2:
		result = sprintf("%s\n    怪物会从城外源源不断地发动攻击，而且是一波的攻势会比一波强。你的任务就是阻挡这些怪物的前进，"HIR"不要让这些怪物接近皇宫的门口半步"NOR"！要记住，一旦侵入皇宫的怪物数量"HIR"达到100只"NOR"，那么我们便彻底失败了。另外也必须注意，如果战场中累积的怪物数量"HIR"达到250只"NOR"，这场战斗也会失败的。\n    每隔几轮攻击，妖魔的头目便会出现，它们的能力十分强大。如果你能消灭它们，说不定会得到宝石之类珍贵物品的奖励。\n", who->get_name());
		result += ESC"离开";
		send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
		break;
	case 10:
		if (__FILE__->get_state()==0)
		{
			result = sprintf("%s\n    虽然现在看起来城外聚集的怪物仍旧没有什么动静，但是据可靠情报，在"HIR"本周六的晚上20：30分"NOR"，它们必定会进攻皇城。希望勇士到时能加入我们的大军，共同抵御妖魔的入侵。\n", who->get_name());
			result += ESC"离开";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}
		result = sprintf("%s\n    请根据你的等级，选择与你等级相符的战场。\n", who->get_name());
		all = get_city_war(z);
		if (sizeof(all)!=4)
		{
			result += ESC"离开";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}
		result += sprintf(ESC"玄武门保卫战(40～60级)(人数：%d/40)\ntalk %x# defence.11\n", all[0]->sizeof_player_dbase(), id);
		result += sprintf(ESC"朱雀门保卫战(50～70级)(人数：%d/40)\ntalk %x# defence.12\n", all[1]->sizeof_player_dbase(), id);
		result += sprintf(ESC"青龙门保卫战(60～80级)(人数：%d/40)\ntalk %x# defence.13\n", all[2]->sizeof_player_dbase(), id);
		result += sprintf(ESC"白虎门保卫战(81级以上)(人数：%d/40)\ntalk %x# defence.14\n", all[3]->sizeof_player_dbase(), id);
		result += ESC"离开";
		send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
		break;
	case 11:
	case 12:
	case 13:
	case 14:
		switch(flag-11)
		{
		case 0: begin = 40; end = 60; name = "玄武门"; break;
		case 1: begin = 50; end = 70; name = "朱雀门"; break;
		case 2: begin = 60; end = 80; name = "青龙门"; break;
		case 3: begin = 81; end = 200; name = "白虎门"; break;
		}
		if (me->get_level()<begin)
		{
			result = sprintf("%s\n    以你当前的实力，仍不足以参加%s的保卫战，为了你的安全着想，还是选择一个适合你自己等级的战场挑战吧。\n", who->get_name(), name);
			result += ESC"离开";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}
		if (me->get_level()>end)
		{
			result = sprintf("%s\n    以你当前的实力，%s的战斗对你来说太过容易了，如果你希望更进一层楼，还是选择一个适合你自己等级的战场挑战吧。\n", who->get_name(), name);
			result += ESC"离开";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}
		all = get_city_war(z);
		if (sizeof(all)!=4) return;
		flag -= 11;
		if (all[flag]->get_war()==2)
		{
			result = sprintf("%s\n    实在抱歉，这个战场已结束战争。\n", who->get_name() );
			result += ESC"离开";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}
		all[flag]->sub_player(me);
		if (all[flag]->sizeof_player_dbase()>=40)
		{
			result = sprintf("%s\n    实在抱歉，这个战场的参加人数已经达到上限了。你还是另外挑选一个适合的战场吧。\n", who->get_name() );
			result += ESC"离开";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}		
		z = all[flag]->get_id();
		if (random(2)) p = get_jumpin(z, 11);
		else p = get_jumpin(z, 12);
		if( p )
		{
			me->add_to_scene(z, p / 1000, p % 1000, 3);
			send_user(me, "%c%w", 0x1f, 8860);
			all[flag]->add_player(me);
		}		
	}
}
void before_destruct()
{
	end_defence();
}