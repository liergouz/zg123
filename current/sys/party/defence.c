/*****�ٱ��������Ѳ�****/

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>
#include <action.h>
#include <map.h>

#define MAX_DEFENCE	77

mapping DefenceMap = ([ ]);	// ���лʳǱ���ս�ĵ�ͼ

int defencecount;			// ���ɵļ����������ʱ�ؿ��µ�ͼʱ���ж�
int endcount;				// ս����ɵļ���
int War;				// ս��ʱ��ļ���
int State;				// ս��״̬ 0: δ���� 1 ���Խ���
void start_defence();
void end_defence();

// ���������ɶ�������
void SAVE_BINARY() { }
// ���������촦��
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
		CHAT_D->sys_channel(0,HIY"����������ħ�Ѿ�������ָ����Ƕ�����"HIR"�߹��Ĵ󽫾�"HIY"���Ѿ�չ��������ļ���ж�����־Ը����ʿ���ٵ����������ϣ�����������ħ�Ĵ����");
	}
	else
	if (War%11==0) CHAT_D->sys_channel(0,HIY"����������ħ�Ѿ�������ָ����Ƕ�����"HIR"�߹��Ĵ󽫾�"HIY"���Ѿ�չ��������ļ���ж�����־Ը����ʿ���ٵ����������ϣ�����������ħ�Ĵ����");
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
	CHAT_D->sys_channel(0,HIY"��˵����������ħ�������������ƻ���"HIR"10���Ӻ�"HIY"���������ʳǡ���"HIR"�����󽫾�"HIY"���Ѿ���ʼ����ļ���ж�����־Ը���ٵ���������������������ʳǵı���ս�ɣ�");
	DefenceMap[1] = ({ });
	DefenceMap[2] = ({ });
	DefenceMap[3] = ({ });
	DefenceMap[4] = ({ });
	DefenceMap[5] = ({ });
	DefenceMap[6] = ({ });
	DefenceMap[7] = ({ });
	// ��ʼ���߸����ҹ�77�ŵ�ͼ
	for (i=0;i<4;i++)
	{
		for (j=1;j<=7;j++)
		{
			if( ( z = find_map_flag(NEWBIE_MAP_BEGIN, NEWBIE_MAP_END, 0) ) > 0 )
			{
				p = 886;
				init_virtual_map(z, p);    // ���������ͼ
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
		result = sprintf("%s\n    ��̽�ӻر�������ʳ���Χ���ۼ��˲�����ħ��֣��������Ǽ����ܵ�һ��ǰ��δ�еĺƽ٣�������Ӣ�����ˣ�����书�ض���ǿ�����ʴ����Ƿ�Ը��������ǵľ��ӣ���ͬ�ֿ���ħ�������أ�\n", who->get_name());
		result += sprintf(ESC"�˽�����\ntalk %x# defence.2\n",id);
		result += sprintf(ESC HIY "���뱣��ս\ntalk %x# defence.10\n",id);
		result += ESC"�뿪";
		send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
		break;
	case 2:
		result = sprintf("%s\n    �����ӳ���ԴԴ���ϵط���������������һ���Ĺ��ƻ��һ��ǿ�������������赲��Щ�����ǰ����"HIR"��Ҫ����Щ����ӽ��ʹ����ſڰ벽"NOR"��Ҫ��ס��һ������ʹ��Ĺ�������"HIR"�ﵽ100ֻ"NOR"����ô���Ǳ㳹��ʧ���ˡ�����Ҳ����ע�⣬���ս�����ۻ��Ĺ�������"HIR"�ﵽ250ֻ"NOR"���ⳡս��Ҳ��ʧ�ܵġ�\n    ÿ�����ֹ�������ħ��ͷĿ�����֣����ǵ�����ʮ��ǿ����������������ǣ�˵������õ���ʯ֮�������Ʒ�Ľ�����\n", who->get_name());
		result += ESC"�뿪";
		send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
		break;
	case 10:
		if (__FILE__->get_state()==0)
		{
			result = sprintf("%s\n    ��Ȼ���ڿ���������ۼ��Ĺ����Ծ�û��ʲô���������Ǿݿɿ��鱨����"HIR"������������20��30��"NOR"�����Ǳض�������ʳǡ�ϣ����ʿ��ʱ�ܼ������ǵĴ������ͬ������ħ�����֡�\n", who->get_name());
			result += ESC"�뿪";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}
		result = sprintf("%s\n    �������ĵȼ���ѡ������ȼ������ս����\n", who->get_name());
		all = get_city_war(z);
		if (sizeof(all)!=4)
		{
			result += ESC"�뿪";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}
		result += sprintf(ESC"�����ű���ս(40��60��)(������%d/40)\ntalk %x# defence.11\n", all[0]->sizeof_player_dbase(), id);
		result += sprintf(ESC"��ȸ�ű���ս(50��70��)(������%d/40)\ntalk %x# defence.12\n", all[1]->sizeof_player_dbase(), id);
		result += sprintf(ESC"�����ű���ս(60��80��)(������%d/40)\ntalk %x# defence.13\n", all[2]->sizeof_player_dbase(), id);
		result += sprintf(ESC"�׻��ű���ս(81������)(������%d/40)\ntalk %x# defence.14\n", all[3]->sizeof_player_dbase(), id);
		result += ESC"�뿪";
		send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
		break;
	case 11:
	case 12:
	case 13:
	case 14:
		switch(flag-11)
		{
		case 0: begin = 40; end = 60; name = "������"; break;
		case 1: begin = 50; end = 70; name = "��ȸ��"; break;
		case 2: begin = 60; end = 80; name = "������"; break;
		case 3: begin = 81; end = 200; name = "�׻���"; break;
		}
		if (me->get_level()<begin)
		{
			result = sprintf("%s\n    ���㵱ǰ��ʵ�����Բ����Բμ�%s�ı���ս��Ϊ����İ�ȫ���룬����ѡ��һ���ʺ����Լ��ȼ���ս����ս�ɡ�\n", who->get_name(), name);
			result += ESC"�뿪";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}
		if (me->get_level()>end)
		{
			result = sprintf("%s\n    ���㵱ǰ��ʵ����%s��ս��������˵̫�������ˣ������ϣ������һ��¥������ѡ��һ���ʺ����Լ��ȼ���ս����ս�ɡ�\n", who->get_name(), name);
			result += ESC"�뿪";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}
		all = get_city_war(z);
		if (sizeof(all)!=4) return;
		flag -= 11;
		if (all[flag]->get_war()==2)
		{
			result = sprintf("%s\n    ʵ�ڱ�Ǹ�����ս���ѽ���ս����\n", who->get_name() );
			result += ESC"�뿪";
			send_user(me ,"%c%c%w%s", ':', 3, who->get_char_picid(), result);
			break;
		}
		all[flag]->sub_player(me);
		if (all[flag]->sizeof_player_dbase()>=40)
		{
			result = sprintf("%s\n    ʵ�ڱ�Ǹ�����ս���Ĳμ������Ѿ��ﵽ�����ˡ��㻹��������ѡһ���ʺϵ�ս���ɡ�\n", who->get_name() );
			result += ESC"�뿪";
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