
#include <ansi.h>
#include <equip.h>
#include <city.h>
#include <map.h>
#include <task.h>

//	�����б�  1~6 ����Ժ����	10 ��������	20 ��������

string * task1 = ({ "�����ͷ��", "����Ŀ���", "ͭ��", "ͭ��", "ͭ��", "ͭ˿", "ͭƬ", "�鲼", "СͭƬ", "ͭ��", "����", "���ع�", "�عϽ�����", "����ʯ", "�ȱ�ʯ", "��֮��", "�׳���", "�Ʒ��", "���", "����β��", "����", "�̰���ʯ", "�̰ױ�ʯ", "���֮��", "��β��", "����", "�鴮", "����", "����ʯ", "������", "����", "����", "����", "����", "����", "��˿", "��Ƭ", "˿��", "˿��", "��ը�ع�Ƭ", "С����", "С��ͭƬ", "��ͭ��", "�ұ�ʯ", "��Ƥҩ��", "�ƾɵ�ͷ��", "�ƾɵĿ���", "�����ʯ", "������Ƭ", "Ыβ", "֩��˿", "�綾��", "��챦ʯ", "������", "���������", "���װ�", "��ͭ��", "ţ��", "�ǻ�", "ˮ��ͷ��", "����", "�����ʯͷ", "����β��", "��ɫСʯͷ", "����ʯ", "�ױ�ʯ", "����", "����", "����", "��˿", "��Ƭ", "����", "����", "����", "��˿", "��������", "������¶", "���׿�", "���߷�", "Ұ�ջ���", "���η�", "��Ƭ", "�", "���", "������", "��ɽ��֥", "С��Ƭ", "����", "��ǯ��", "�Ʋ���", "�����ʯ", "��ױ�ʯ", "����", "��ɫСʯͷ", "������ʯ", "���̱�ʯ", "��������", "ñӧ", "�ƾɵ�ͷ��", "�ƾɵĿ���", "����", "����", "��Ͳ", "ī����ʯ", "ī��ʯ", "���", "����", "��", "��˿", "��Ƭ", "Ƥ��", "ɴ", "ɴ��", "���䵤", "������", "������", "ˮ����Ϲ�", "С��Ƭ", "����", "ǹͷ", "���", "�ɺ���", "�ɳ�Ƥ", "���˿", "������", "��������", "���", "ͭ��", "��ɫСʯͷ", "����", "ͭ��", "����ʯ", "������", "������", "������", "����˿", "����Ƭ", "������", "������", "������", "��ңɢ", "���ĵ�", "ˮ����Ϲ�", "�Ϲϱ�", "����˿", "����Ƭ", "�౦ʯ", "��ɫ����", "����", "�Ƕ�", "����ͷ", "��ľ��", "��ʬ��", "����ʯ", "�̱�ʯ", "����", "��ٸ֮��", "��ٸ֮��", "��ħ��", "����", "С̫��", "���", "���", "����ʯ", "������", "���֮��", "����", "������ʯ", "���౦ʯ", "����ʯ", "�챦ʯ", "����ʯ", "�ʲ�Ƭ", "���η�", "����Ƭ", "������", "���", "�غ컨", });
int * count1 = ({ 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, });
string * unit1 = ({ "��", "��", "��", "��", "��", "��", "��", "��", "Ƭ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ֻ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", });
string * task2 = ({ "���ֿ�", "��ͯ", "������", "����", "����", "����", "���", "κ�ܼ�", "����", "����", "����", "��С��", "����", "��ܼ�", "������", "���", "��ľ", "��Ϊ", "����", "Ǯ�ϰ�", "���ܼ�", "��ͷ", "Ǯ�Ͼ�", "��½", "����", "���ܼ�", "������", "�ŷ�", "���", "����", "�Թܼ�", "����", "����", "�ĺ", "�عܼ�", "����", "������", "�̷�", "��ܼ�", });
//string * food = ({ "ˮ��", "����", "����", "С��", "����", "����", "�Ϲ�", "�ƹ�", "�ܲ�", "�ײ�", "���", "�ع�", "ɽҩ", });
string * food = ({ "���ع�", "�عϽ�����", "��ը�ع�Ƭ", "С����", "���װ�", "���׸�", });
// �ڲ��ڼ�����ܷ��ʱ��ʱ�õ���Ʒ
string * task3 = ({ "�����ͷ��", "����Ŀ���", "��֮��", "�׳���", "�Ʒ��", "���", "����β��", "����", "���֮��", "��β��", "����", "�鴮", "����", "������", "����", "����", "��Ƥҩ��", "�ƾɵ�ͷ��", "�ƾɵĿ���", "������Ƭ", "Ыβ", "֩��˿", "�綾��", "ţ��", "�ǻ�", "ˮ��ͷ��", "����", "�����ʯͷ", "����β��", "��ɫСʯͷ", "��ǯ��", "�Ʋ���", "����", "��ɫСʯͷ", "��������", "ñӧ", "�ƾɵ�ͷ��", "�ƾɵĿ���", "����", "����", "��Ͳ", "ǹͷ", "���", "ͭ��", "��ɫСʯͷ", "����", "ͭ��", "��ɫ����", "����", "�Ƕ�", "����ͷ", "��ľ��", "��ʬ��", "����", "��ٸ֮��", "��ٸ֮��", "��ħ��", "����", "С̫��", "���", "���", "����ʯ", "������", "���֮��", "����",});

// ���������ɶ�������
void SAVE_BINARY() { }

void init_org_place(int z, string name, object orgnpc);

// ���ҵİ����ܹ�
void do_look_1(object me, object who )
{
	string result;
	int position;
	"/quest/help"->send_help_tips(me, 26);
	result = sprintf("%s��\n    ���Ǹ���%s����������ܹܣ�����ʲô����Ҫ�Ұ�æ����\n", who->get_name(), who->get_city_name());
	position = me->get_org_position();
	if (position>0 && me->get_city_name()==who->get_city_name()&&me->get_org_name()!="")
		result += sprintf(ESC"�ذ���Ժ��\ntalk %x# back\n", getoid(who));
	else
	if (position==0 && me->get_city_name()==who->get_city_name() && me->get_org_name()!="" )
		result += sprintf(ESC"��������\ntalk %x# info.10\n", getoid(who));
	else
	{
		if (me->get_org_name()=="")
		{
			result += sprintf(ESC"�������\ntalk %x# info.20\n", getoid(who));
			result += sprintf(ESC"���뽨��\ntalk %x# info.30\n", getoid(who));
		}
	}
	result += sprintf(ESC"�ι���������\ntalk %x# travel\n", getoid(who));
	result += sprintf(ESC"�뿪\nCLOSE\n");
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
}

// �ذ���
void do_back(object me, object who, string arg )
{
	string result, name;
	int position;
	object map, orgnpc, npc;
	int i, size, z, p, x, y, x0, y0;
	position = me->get_org_position();
	name = me->get_org_name();
	if (name=="") return;
	if (position>0 && me->get_city_name()==who->get_city_name())
	{
		orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
		if (!objectp(orgnpc)) return;
		map = orgnpc->get("map");
		if (map==0)
		{
			if( ( z = find_map_flag(NEWBIE_MAP_BEGIN, NEWBIE_MAP_END, 0) ) > 0 )
			{
				p = 886;
				init_virtual_map(z, p);    // ���������ͼ
				map = new( "/inh/std/org" );
				map->set_client_id(p);
				set_map_object( map, map->set_id(z) );
				orgnpc->set("map", map);
				orgnpc->set("z", z);
				map->set_name(name);
				init_org_place(z, name, orgnpc);
			}
			else
				return ;
		}
		else
		{
			z = orgnpc->get("z");
		}
		me->set_2("jiguan.z", get_z(me));
		me->set_2("jiguan.x", get_x(me));
		me->set_2("jiguan.y", get_y(me));
		if (random(2)) p = get_jumpin(z, 11);
		else p = get_jumpin(z, 12);
		if( p )
		{
			me->add_to_scene(z, p / 1000, p % 1000, 3);
		}
	}
}

// �����ܹܵ���غ���
void do_info(object me, object who, string arg )
{
	int position, flag, number, i, size;
	string result, name;
	object orgnpc, city, *char, item;
	position = me->get_org_position();
	flag = to_int(arg);
	name = me->get_org_name();
	if (flag>=10&&flag<20)
	{
		if (name=="") return;
		if (position>0)
		{
			result = sprintf("%s��\n    ���Ѿ��������С�\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return ;
		}
		if (flag==10)
		{
			result = sprintf("%s��\n    ����ķ�������%s��\n", who->get_name(), name);
			result += sprintf(ESC"ȷ��\ntalk %x# info.11\n", getoid(who));
			result += ESC"ȡ��\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
		number = me->get_number();
		if (objectp(orgnpc))
		{
	                if( orgnpc->get_join_id(number) )
	                {
	                        orgnpc->delete_join_info(number);
				orgnpc->save();
	                }
		}
		me->set_org_name("");
		result = sprintf("%s��\n    ���Ѿ�ȡ����������%s�����룬��ʲô��Ҫ��æ���������Ұɡ�\n", who->get_name(), name);
		result += ESC"�뿪\nCLOSE\n";
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return ;
	}
	if (name!="") return;
	if (flag>=20&&flag<30)
	{
		switch (flag)
		{
		case 20:
			result = sprintf("%s��\n    ��ϣ��������뱾���İ��������Ҫ������뱾���İ��ɣ��������ȼ��뱾���������߱����޹����������ϣ������һ�������Լ��İ�ᣬ���˱����Ϊ���������⣬������õ�һ����Ϊ����֮�Žǡ������\n", who->get_name());
			result += sprintf(ESC"ȷ��\ntalk %x# info.21\n", getoid(who));
			result += sprintf(ESC"����\ntalk %x# info.29\n", getoid(who));
			break;
		case 21:
			if (me->get_city_name()!=who->get_city_name()&& me->get_city_name()!="" && me->get_city_name()!=0 )
			{
				result = sprintf("%s��\n    �����б���Ĺ��������޷���������������롣\n", who->get_name());
			}
			else
			{
				if( !( city = CITY_D->get_city_object(who) ) ) return ;
				char = city->get("manager");
				send_user(me, "%c%c%c%d", 0x95, 53, 1, getoid(who));
				size = sizeof(char);
				for (i=0;i<size;i++) if (objectp(char[i]))
				{
					result = sprintf("%-4s%-12s%s", who->get_city_name(), char[i]->get_org_name(), char[i]->get_master_name() );
					send_user(me, "%c%c%c%d%c%w%w%s", 0x95, 53, 2, char[i]->get_power(), char[i]->get_grade(), char[i]->sizeof_member_dbase(), char[i]->get_max_number(), result);
				}
				return ;
			}
			break;
		case 29:
			do_look_1(me, who);
			return;

		}
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (me->get_city_name()!=who->get_city_name())
	{
		result = sprintf("%s��\n    �������Ǳ����Ĺ������޷��������Ľ������롣\n", who->get_name());
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return ;
	}
	if (me->get_level()<40)
	{
		result = sprintf("%s��\n    ���ĵȼ�������40�����޷��е����ΰ���\n", who->get_name());
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	switch(flag)
	{
	case 30:
		result = sprintf("%s��\n    �����˻�����������־���������������ɿɲ���һ�����׵����飬�������Ƚ�����һ����Ϊ����֮�Žǡ���������֤���Լ��������������Ҳ���ͨ�����������ɵ����롣\n", who->get_name());
		result += sprintf(ESC"��������֮�Žǡ�\ntalk %x# info.31\n", getoid(who));
		result += ESC"�뿪\nCLOSE\n";
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	case 31:
		if( objectp( item = present("��֮�Ž�", me, 1, MAX_CARRY*4) ) )
		{
		        result = sprintf("%s��\n    û����Ȼ�������ġ���֮�Žǡ���������Ѱ������Ž���Ҳ���˲��ٵĹ��򡣺ã��Ϸ����������Ը���������������ɰɣ�\n", who->get_name());
			result += sprintf(ESC"��������\ntalk %x# info.32\n", getoid(who));
			result += ESC"�һ����ٿ��ǿ��ǡ���\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		result = sprintf("%s��\n    ����֮�Žǡ���û�������ܹ�������үүӦ��֪�������й�����Žǵ�һЩ�������������ȥѯ��һ�������ڡ���֮�Žǡ������顣����үү�����ܹ���̳�����ģ���������������������ġ�\n", who->get_name());
		result += ESC"�뿪\nCLOSE\n";
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	case 32:
		if( objectp( item = present("��֮�Ž�", me, 1, MAX_CARRY*4) ) )
		{
		        name = me->get("org");
		        if( !stringp(name) || name == "" )
		                send_user( me, "%c%c%d%s", '?', 16, 11, "�����ڴ˴������ɣ��������������(������������)��\n" ESC "org @ %s\n" );
		        else    "cmd/user/org"->main(me, "@ " + name);
		        return ;
		}
		break;
	}
}

// �ι���������
void do_travel(object me, object who, string arg )
{
	string name, result;
	object map, orgnpc, city, *char;
	int i, size, z, p, x, y, x0, y0;
	if (arg==""||arg==0)
	{
		if( !( city = CITY_D->get_city_object(who) ) ) return ;
		char = city->get("manager");
		send_user(me, "%c%c%c%d", 0x95, 54, 1, getoid(who));
		size = sizeof(char);
		for (i=0;i<size;i++) if (objectp(char[i]))
		{
			result = sprintf("%-4s%-12s%s", who->get_city_name(), char[i]->get_org_name(), char[i]->get_master_name() );
			send_user(me, "%c%c%c%d%c%w%w%s", 0x95, 54, 2, char[i]->get_power(), char[i]->get_grade(), char[i]->sizeof_member_dbase(), char[i]->get_max_number(), result);
		}
		return;
	}
	name = arg;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	result = sprintf("%s��\n    ��ϣ���ι�һ��%s�𣿺����ף���ֻҪ����2000���ұ���԰��������롣\n", who->get_name(), name);
	result += sprintf(ESC"ȷ��\ntalk %x# travel2.%s\n", getoid(who), name);
	result += ESC"�뿪\nCLOSE\n";
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
	send_user(me, "%c%c", 0x95, 255);
}

// ������������
void do_travel2(object me, object who, string arg )
{
	string name, result;
	object map, orgnpc, npc;
	int i, size, z, p, x, y, x0, y0;
	if (arg=="") return;
	name = arg;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	if (me->get_cash()<2000)
	{
		result = sprintf("%s��\n    ûǮ������ʲô��Ц���ȴ���2000��֮�������ɣ�\n", who->get_name());
		result += ESC"�뿪\nCLOSE\n";
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return ;
	}
	me->add_cash(-2000);
	"/sys/sys/count"->add_use("visit", 2000);
	me->log_money("�ι�", -2000);
	orgnpc->add_gold(1000);
	map = orgnpc->get("map");
	if (map==0)
	{
		if( ( z = find_map_flag(NEWBIE_MAP_BEGIN, NEWBIE_MAP_END, 0) ) > 0 )
		{
			p = 886;
			init_virtual_map(z, p);    // ���������ͼ
			map = new( "/inh/std/org" );
			map->set_client_id(p);
			set_map_object( map, map->set_id(z) );
			orgnpc->set("map", map);
			orgnpc->set("z", z);
			map->set_name(name);
			init_org_place(z, name, orgnpc);
		}
		else
			return ;
	}
	else
	{
		z = orgnpc->get("z");
	}
	me->set_2("jiguan.z", get_z(me));
	me->set_2("jiguan.x", get_x(me));
	me->set_2("jiguan.y", get_y(me));
	if( p = get_jumpin(z, 10) )
	{
		me->add_to_scene(z, p / 1000, p % 1000, 3);
	}
}

// ����������
void do_join(object me, object who, string arg )
{
	string name, result;
	object map, orgnpc;
	int i, size, z, p, x, y, x0, y0;
	if (me->get_city_name()!="" && me->get_city_name()!=who->get_city_name()) return;
	if (me->get_org_name()!="") return;
	name = arg;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	if ("/sys/city/manager2"->do_join( me, orgnpc, "" )==1)
	{
//		me->set_org_name(name);
		result = sprintf("%s��\n    �����������Ҹղ��Ѿ�ί�в���ת����%s��%s�����ˣ����;������ɡ�\n", who->get_name(), name, orgnpc->get_master_name());
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		send_user(me, "%c%c", 0x95, 255);
	}
}

// ��������ܹ�
void do_look_2(object me, object who )
{
	string result, name;
	object orgnpc;
	int position, id;
	name = who->get_org_name();
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	result = sprintf("%s��\n    �ұ���%s���ܹܣ�����ͳ�����%s���һ���ճ������������к�Ҫ�£�\n", who->get_name(), name, name);
	position = me->get_org_position();
	if ((me->get_org_name()==name) && (position>0))
	{
		id = getoid(who);
		result += sprintf(ESC"�鿴���ɳ�Ա����\ntalk %x# info\n", id);
		result += sprintf(ESC"���ɹ�������¼�\ntalk %x# note\n", id);
		result += sprintf(ESC"����ս��\ntalk %x# war\n", id);
		result += sprintf(ESC"����״��\ntalk %x# org\n", id);
		if (position==9 && orgnpc->get_demisstime()>time())
			result += sprintf(ESC"ȡ������\ntalk %x# quest.30\n", id);
		if (me->get_save_2("orgtask2.type")==0)
			result += sprintf(ESC"��ȡ����Ժ����\ntalk %x# quest.10\n", id);
		else
			result += sprintf(ESC"�������Ժ����\ntalk %x# quest.20\n", id);
	}
	result += sprintf(ESC"�뿪\nCLOSE\n");
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
}

// ���ɵ����ͷ
void do_look_3(object me, object who )
{
	string result, name;
	int position, count, i;
	object orgnpc;
	result = sprintf("%s��\n    ����ר�Ÿ�����ɵ�ѵ����ս����Ա����ļ��\n", who->get_name());
	position = me->get_org_position();
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	if (position>0 && me->get_org_name()==who->get_org_name())
	{
		count = 0;
		for (i=0;i<=8;i++) if (orgnpc->get_strong(i)) count ++;
		result += sprintf("Ŀǰ�����ѵ����Ϊ%d��������%d��ǿ��ѵ������Ҫ��Щʲô��\n", orgnpc->get_train(), count );
		if (position>=8)
			result += sprintf(ESC"����ǿ����\ntalk %x# info.10\n", getoid(who));
		if (count>0) result += sprintf(ESC"ѧϰǿ����\ntalk %x# info.20\n", getoid(who));
		if (position>=8)
		{
			result += sprintf(ESC"����ѵ����\ntalk %x# info.50\n", getoid(who));
//???			result += sprintf(ESC"Ƹ������ػ���\ntalk %x# info.40\n", getoid(who));
		}
	}
	result += sprintf(ESC"�뿪\nCLOSE\n");
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
}

// ���ͷ����غ���
void do_info_3(object me, object who, string arg )
{
	int position, flag, number, i, size, level, time, cash,level1;
	string result, name, list, desc;
	object orgnpc, city, *char, item, file;
	position = me->get_org_position();
	flag = to_int(arg);
	name = me->get_org_name();
	if (position==0 || name=="" || name!=who->get_org_name()) return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	switch(flag)
	{
	case 10:
		if (position<8) return;
		list = "";
		size = orgnpc->get_strongcount();
		if (size>0)
		{
			for (i=0;i<=8;i++) if (orgnpc->get_strong(i))
			{
				file = load_object(sprintf("/skill/04/%04d", 430+i));
				if (file)
				{
					if (list=="") list = file->get_name();
					else list = list + "��" + file->get_name();
				}
			}
			if (size>=orgnpc->get_grade()*2)
			{
				result = sprintf("%s��\n    Ŀǰ�����Ѿ�������%d��ǿ����%s�����Ѿ��ﵽ�ɿ������ޡ����������ɹ�ģ�������鿴��\n", who->get_name(), size, list);
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return;
			}
			result = sprintf("%s��\n    Ŀǰ�������Ѿ�������%d��ǿ����%s������û�ﵽ�ɿ������ޣ���ѡ���迪����ǿ������ÿ����һ��ǿ�����İ����ʽ�500�򣬴���200��\n", who->get_name(), size, list);
		}
		else
			result = sprintf("%s��\n    ��ѡ���迪����ǿ������ÿ����һ��ǿ�����İ����ʽ�500�򣬴���200��\n", who->get_name());
		for (i=0;i<=8;i++) if (orgnpc->get_strong(i)==0)
		{
			file = load_object(sprintf("/skill/04/%04d", 430+i));
			if (file)
			{
				result += sprintf(ESC"%s\ntalk %x# info.%d\n", file->get_name(), getoid(who), 11+i);
			}
		}
		result += sprintf(ESC"�뿪\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 41:
	case 42:
	case 43:
	case 44:
	case 45:
	case 46:
	case 47:
	case 48:
	case 49:
		if (position<8) return;
		i = (flag-1)%10;
		if (orgnpc->get_strong(i)) return;
		file = load_object(sprintf("/skill/04/%04d", 430+i));
		if (!file) return;
		size = orgnpc->get_strongcount();
		if (size>=orgnpc->get_grade()*2)
		{
			result = sprintf("%s��\n    Ŀǰ�����Ѿ�������%d��ǿ�����Ѿ��ﵽ�ɿ������ޡ����������ɹ�ģ�������鿴��\n", who->get_name(), size);
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (orgnpc->get_train()<(size+1)*10+5)
		{
			result = sprintf("%s��\n    Ŀǰ���ɵ�ѵ���Ȳ���%d������������ѵ���Ⱥ�����ǿ�����ܡ�\n", who->get_name(), (size+1)*10+5);
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (orgnpc->get_gold()<5000000)
		{
			result = sprintf("%s��\n    Ŀǰ���ɵ��ʽ���500���������ʽ������ǿ�����ܡ�\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (orgnpc->get_store()<200)
		{
			result = sprintf("%s��\n    Ŀǰ���ɵĴ�������200�������Ӵ���������ǿ�����ܡ�\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (flag<30)
		{
			desc = file->get_desc();
			result = sprintf("%s��\n    %s%s��ȷ��Ҫ��������ǿ��������\n", who->get_name(), file->get_name(), desc[25..<2], );
			result += sprintf(ESC"ȷ��\ntalk %x# info.%d\n", getoid(who), 41+i);
			result += sprintf(ESC"ȡ��\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		orgnpc->add_gold(-5000000);
		orgnpc->set_store(orgnpc->get_store()-200);
		orgnpc->set_strong(i);
		orgnpc->save();
		result = sprintf("%s��\n    ��������%s�����İ����ʽ�500�򣬴���200��\n", who->get_name(), file->get_name());
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		FAMILY_D->org_channel( name, 0, sprintf( HIR "�������Ѿ��������µ�ǿ�����⼼��%s����",
			file->get_name() ) );
		break;
	case 20:
		result = sprintf("%s��\n    ���г�Ա�������������ǿ��ѵ����ѵ���Ĵ�����ÿ����һ��ǿ������Ҫ��Ǯ20000�����ɹ��׶�5��Ǳ��50��ǿ�����ܵĲ�ͬ�����ѵĽ�ǮҲ��ͬ�����⣬��İ����ܹ���Ҳ����ﵽ3000��ſ���������ѡ����ϣ��ǿ������Ŀ��\n", who->get_name());
		for (i=0;i<=8;i++) if (orgnpc->get_strong(i))
		{
			file = load_object(sprintf("/skill/04/%04d", 430+i));
			if (file)
			{
				result += sprintf(ESC"%s\ntalk %x# info.%d\n", file->get_name(), getoid(who), 21+i);
			}
		}
		result += sprintf(ESC"�뿪\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 21:
	case 22:
	case 23:
	case 24:
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
		i = (flag-1)%10;
		file = load_object(sprintf("/skill/04/%04d", 430+i));
		if (!file) return;
		cash = file->get_learn_money();
		if (cash==0) cash = 30000;
		result = sprintf("%s��\n    ǿ��%sһ�Σ�ֻ�������ü���5�������ȣ���ÿ����Ҫ�ķѽ�Ǯ%d�����ɹ��׶�5�㣬50��Ǳ��ֵ����ȷ��Ҫǿ����\n", who->get_name(), file->get_name(), cash );
		result += sprintf(ESC"ȷ��\ntalk %x# info.%d\n", getoid(who), 31+i);
		result += sprintf(ESC"ȡ��\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 31:
	case 32:
	case 33:
	case 34:
	case 35:
	case 36:
	case 37:
	case 38:
	case 39:
		i = (flag-1)%10;
		if (orgnpc->get_strong(i)==0) return;
		file = load_object(sprintf("/skill/04/%04d", 430+i));
		if (!file) return;
//		if ( (i==6)&&me->get_skill(430+i)>=5)
//		{
//			result = sprintf("%s��\n    ����%s�Ѵ����ޡ�\n", who->get_name(), file->get_name());
//			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
//			return;
//		}
		if ( i == 6 )
			level1 = 5;
		else if ( i == 0 || i == 1 || i == 2 || i == 3 || i == 7 || i == 8 )
			level1 = 20;
		else
			level1 = 10;
		if(me->get_skill(430+i)>=level1)
		{
			result = sprintf("%s��\n    ����%s�Ѵ����ޡ�\n", who->get_name(), file->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
//		if(me->get_skill(430+i)>=me->get_level()/10-2)
//		{
//			result = sprintf("%s��\n    ��ֻ������%d�����ܼ�������%s��\n", who->get_name(), (me->get_level()/10+1)*10, file->get_name());
//			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
//			return;
//		}
		cash = file->get_learn_money();
		if (cash==0) cash = 30000;
		if (me->get_cash()<cash)
		{
			result = sprintf("%s��\n    ���Ľ�Ǯ����%d�����ܽ���ǿ��ѵ����\n", who->get_name(), cash);
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		number = me->get_number();
		if (orgnpc->get_member_all_contribute(number)<3000)
		{
			result = sprintf("%s��\n    ���İ����ܹ��׶Ȳ���3000�����ܽ���ǿ��ѵ����\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (orgnpc->get_member_contribute(number)<5)
		{
			result = sprintf("%s��\n    ���İ��ɹ��׶Ȳ����Խ���ǿ��ѵ����\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (me->get_potential()<50)
		{
			result = sprintf("%s��\n    ����Ǳ�ܲ����Խ���ǿ��ѵ����\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		me->add_cash(-cash);
		"/sys/sys/count"->add_use("org-strong", cash);
		me->log_money("ǿ������", -cash);
		orgnpc->set_member_contribute(number, orgnpc->get_member_contribute(number)-50);
		me->set_potential(me->get_potential()-50);
		me->improve_skill(430+i, 50);
		level = me->get_skill(430+i);
		result = sprintf("%s��\n    ��ǿ��%s����������5��Ŀǰ�ȼ�%d���������� %d / %d ��\n", who->get_name(), file->get_name(), level, me->get_skill_degree(430+i),(level+1)*(level+1)*5);
		result += sprintf(ESC"����ѧϰ\ntalk %x# info.%d\n", getoid(who), 31+i);
		result += sprintf(ESC"ȡ��\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 50:
	case 51:
		time = orgnpc->get_traintime();
		if (time>0)
		{
			if (time()>time)
			{
				orgnpc->set_traintime(0);
				orgnpc->set_train(orgnpc->get_train()+1);
			}
			else
			{
				result = sprintf("%s��\n    ����ѵ����������ʣ��%d���ӡ�\n", who->get_name(), (time-time())/60 );
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return;
			}
		}
		if (orgnpc->get_train()>=20*orgnpc->get_grade())
		{
			result = sprintf("%s��\n    ����ѵ�����Ѵ����ޡ�\n", who->get_name() );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (orgnpc->get_gold()<2000000)
		{
			result = sprintf("%s��\n    �����ʽ���200���޷�����ѵ���ȡ�\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (orgnpc->get_store()<60)
		{
			result = sprintf("%s��\n    ���ɴ�������60���޷�����ѵ���ȡ�\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (flag==30)
		{
			result = sprintf("%s��\n    Ŀǰ�����ɵ�ѵ����Ϊ%d������1��ѵ������Ҫ���İ����ʽ�200���Լ�����60���ұ����ʱʮ�룬��ȷ��Ҫ�������ɵ�ѵ������\n", who->get_name(), orgnpc->get_train() );
			result += sprintf(ESC"ȷ��\ntalk %x# info.51\n", getoid(who));
			result += sprintf(ESC"ȡ��\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		orgnpc->add_gold(-2000000);
		orgnpc->set_store(orgnpc->get_store()-60);
		orgnpc->set_traintime(time()+1*10);
		orgnpc->save();
		FAMILY_D->org_channel( name, 0, sprintf( HIR "�������Ѿ���ʼ����ѵ���ȣ���ʱΪʮ�롣",
			orgnpc->get_sciencetime() ) );
		break;
	}
}

// ���ɵ��ʷ�����
void do_look_4(object me, object who )
{
	string result, name, *trader;
	int position, store;
	object orgnpc;
	result = sprintf("%s��\n    ��Ϊ�����ɵĲֹܣ���ؾ��ľ���������ϸ�㡣\n", who->get_name());
	position = me->get_org_position();
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	if (position>0 && me->get_org_name()==name)
	{
		store = orgnpc->get_store();
		result += sprintf("����Ŀǰӵ���ʽ�%d������%d������������ʲô������\n", orgnpc->get_gold(), store );
		if (store<orgnpc->get_grade()*500&&(me->get_save_2("orgtask.type")!=1)) result += sprintf(ESC"��ȡ��������\ntalk %x# info.10\n", getoid(who));
		if (me->get_save_2("orgtask.type")==1) result += sprintf(ESC"��ɴ�������\ntalk %x# info.20\n", getoid(who));
		trader = orgnpc->get_trader();
		if (arrayp(trader) && member_array(me->get_id(), trader)!=-1||me->get_number()==orgnpc->get_master())
		{
			if (me->get_save_2("orgtask3.type")==0)
				result += sprintf(ESC"��ȡ��������\ntalk %x# info.30\n", getoid(who));
		}
		if (me->get_save_2("orgtask3.type")==1)
			result += sprintf(ESC"��ɾ�������\ntalk %x# info.40\n", getoid(who));
		result += sprintf(ESC"���\ntalk %x# savings\n", getoid(who));
	}
	result += sprintf(ESC"�뿪\nCLOSE\n");
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
}

// �ʷ���������غ���
void do_info_4(object me, object who, string arg )
{
	int position, flag, number, i, size, level, count, gold, p, exp, contrib, base, rand, order;
	string result, name, list;
	object orgnpc, city, *char, item, file;
	object *inv;
	position = me->get_org_position();
	flag = to_int(arg);
	name = me->get_org_name();
	if (position==0 || name=="" || name!=who->get_org_name()) return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	switch(flag)
	{
	case 10:		// ��������
		if (me->get_save_2("orgtask.type")!=0)
		{
			result = sprintf("%s��\n    ��İ�������û����ɣ�������ȡ������\n", who->get_name());
			result += sprintf(ESC"�뿪\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (time()-me->get_save_2("orgtask.time")<0 ) me->set_save_2("orgtask.time", 0);
		if (time()-me->get_save_2("orgtask.time")<180)
		{
			result = sprintf("%s��\n    ��ȡ��������Ҫ��������ӡ�\n", who->get_name());
			result += sprintf(ESC"�뿪\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		level = orgnpc->get_grade();
//		if (MAIN_D->get_host_type()!=4 && MAIN_D->get_host_type()!=0)
		if (1)
		{
			switch(level)
			{
			case 1:
				size = 64;
				rand = 100 - 64;
				break;
			case 2:
				size = 100;
				rand = 130-100;
				break;
			case 3:
				size = 130;
				rand = 161 - 130;
				break;
			case 4:
				size = 161;
				rand =  sizeof(task1);
				break;
			default:
				size = sizeof(task1);
				rand= 1;
				break;
			}
			base = size;
			i = random(size);
			me->set_save_2("orgtask.double", 0);
			if (level<5)
			{
				if (random(100)<5)
				{
					i = base + random(rand);
					if (i>=sizeof(task1)) i = base;
					me->set_save_2("orgtask.double", 1);
				}
			}
			me->set_save_2("orgtask.status", 1);
			me->set_save_2("orgtask.name", task1[i]);
			me->set_save_2("orgtask.count", count1[i]);
			me->set_save_2("orgtask.unit", "��");
			me->set_save_2("orgtask.time", time());
		}
		else
		{
			switch(level)
			{
			case 1:
				size = 30;
				rand = 38 - 30;
				break;
			case 2:
				size = 38;
				rand = 46-38;
				break;
			case 3:
				size = 46;
				rand = 59 - 46;
				break;
			case 4:
				size = 59;
				rand =  sizeof(task3);
				break;
			default:
				size = sizeof(task3);
				rand= 1;
				break;
			}
			base = size;
			i = random(size);
			me->set_save_2("orgtask.double", 0);
			if (level<5)
			{
				if (random(100)<5)
				{
					i = base + random(rand);
					if (i>=sizeof(task3)) i = base;
					me->set_save_2("orgtask.double", 1);
				}
			}
			me->set_save_2("orgtask.status", 1);
			me->set_save_2("orgtask.name", task3[i]);
			me->set_save_2("orgtask.count", 10);
			me->set_save_2("orgtask.unit", "��");
			me->set_save_2("orgtask.time", time());
		}
		result = sprintf("%s��\n    ���ڰ������ڷ�չ���о���ά���Ĺ�ϵ����Ҫ���������Ĳ����Ա���ʱ֮�衣Ŀǰ���ɻ�ȱ���������ʣ����æȥ�һ����ɡ�\n", who->get_name() );
		result += sprintf(ESC"��������\ntalk %x# info.11\n", getoid(who));
		result += sprintf(ESC"�뿪\ntalk %x# info.12\n", getoid(who));
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 11:
		if (me->get_save_2("orgtask.status")==1) me->set_save_2("orgtask.type", 1);
		if ( me->get("tasklist") != 0 )
		{
			send_user( me, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"��������" );
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 10, "��������" );
		}
		break;
	case 12:
		me->set_save_2("orgtask.status", 0);
		break;
	case 20:
	case 21:
		if (me->get_save_2("orgtask.type")!=1)
		{
			result = sprintf("%s��\n    ��û����ȡ��������\n", who->get_name());
			result += sprintf(ESC"�뿪\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		name = 	me->get_save_2("orgtask.name");
		number = me->get_save_2("orgtask.count");
		list = me->get_save_2("orgtask.unit");
		inv = all_inventory(me, 1, MAX_CARRY*4);
		inv -= ({ 0});
		count = 0;
		for( i = 0, size = sizeof(inv); i < size; i ++ )
		{
			if ( (inv[i]->get_name()==name) && (inv[i]->is_legend_item()==0) )
			{
				if (inv[i]->get_max_combined()<=1) count ++;
				else count += inv[i]->get_amount();
			}
		}
		if (count<number)
		{
			if( !objectp( item = present("������", me, 1, MAX_CARRY*4) ) )
			{
				result = sprintf("%s��\n    ��Ҫ���չ���%d%s%s���뱸����������Ҫ��ʼ���գ������ܰ�;���ϣ������ʵ�����Ҳ�����Ҫ�Ĳ��ϣ������ȥ�ҹ������˰��æ��\n", who->get_name(), number, list, name);
				result += sprintf(ESC"�뿪\nCLOSE\n");
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return;
			}
		}

		if (flag==20)
		{
			if (item)
			{
				result = sprintf("%s��\n    ��ϣ������һ���������������εĴ���������\n", who->get_name() );
				result += sprintf(ESC"ȷ��\ntalk %x# info.21\n", getoid(who));
				result += sprintf(ESC"ȡ��\nCLOSE\n");
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				break;
			}
			result = sprintf("%s��\n    ���ֵ��൱������ô��ͰѶ����ռ�ȫ�ˣ�����Ҫ�Ƕ༸�����������������ˣ��Ժ����۰Ը���֮�ף������������������Ĺ��ͣ��������صĽ����㡣\n", who->get_name() );
			result += sprintf(ESC"�������\ntalk %x# info.21\n", getoid(who));
			result += sprintf(ESC"�뿪\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			break;
		}
		if (item)
		{
			send_user( me, "%c%d", 0x2d, getoid(item) );
                        destruct(item);
		}
		else
		for( i = 0, size = sizeof(inv); i < size; i ++ )
		{
			if ( (inv[i]->get_name()==name) && (inv[i]->is_legend_item()==0) )
			{
				if (inv[i]->get_max_combined()<=1)
				{
					number --;
					send_user( me, "%c%d", 0x2d, getoid(inv[i]) );
                                	destruct(inv[i]);
				}
				else
				{
					if (number > inv[i]->get_amount())
					{
						number -= inv[i]->get_amount();
						send_user( me, "%c%d", 0x2d, getoid(inv[i]) );
                                		destruct(inv[i]);
					}
					else
					{
						inv[i]->add_amount( -number );
						number = 0;
					}
				}
				if (number<=0) break;
			}
		}
		me->add_exp(2000*me->get_online_rate()/100);
		number = me->get_number();
		order = me->get_save_2("orgtask.order");
		order++;
		order = order * me->get_online_rate()/100;
		orgnpc->set_member_contribute(number, orgnpc->get_member_contribute(number)+order);
		orgnpc->set_store(orgnpc->get_store()+1);
		result = sprintf("������˴������񣬾�������%d�����ɹ��׶�����%d��\n", 2000 * me->get_online_rate()/100, order* me->get_online_rate()/100);
		if (me->get_save_2("orgtask.double"))
		{
			me->add_cash(2000* me->get_online_rate()/100);
			me->log_money("��������", 2000* me->get_online_rate()/100);
			"/sys/sys/count"->add_income("org", 2000 * me->get_online_rate()/100);
			orgnpc->set_member_contribute(number, orgnpc->get_member_contribute(number)+3* me->get_online_rate()/100);
			result += sprintf("����õ�%d����ɹ��׵��%d��Ľ�����\n", 3* me->get_online_rate()/100, 2000* me->get_online_rate()/100);
		}
		if (order==10 && random100()<me->get_online_rate())
		{
			if ( me->get_level()>=40 && random100()==0)
			{
				item = new ("/item/01/0007");
			}
			else
				item = new( "sys/item/product"->get_random_mid_product() );
			if (item)
			{
	                        if( USER_INVENTORY_D->can_carry(me, item)  >=1 )
	                        {
	                                p =item->move(me, -1);
	                                item->add_to_user(p);
			                send_user( me, "%c%s", '!', "��������"+item->get_name() );
	                        }
	                        else
	                        	destruct(item);
			}
			if (random100()<5*me->get_online_rate()/100) "/quest/box"->give_box(me);

		}
		me->delete_save_2("orgtask");
		if (order>=10) order = 0;
		me->set_save_2("orgtask.order", order);
		send_user( me, "%c%s", ';', result );
		send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 10,"" );
		send_user( me, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"" );
		break;
	case 30:
	case 31:
		char = orgnpc->get_trader();
		if ( (!arrayp(char) || member_array(me->get_id(), char)==-1) && me->get_number()!= orgnpc->get_master() )
		{
			result = sprintf("%s��\n    �㲻�����ˣ��޷���ȡǮƱ��\n", who->get_name());
			result += sprintf(ESC"�뿪\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
                if( present("ǮƱ", me, 1, MAX_CARRY*4) )
                {
                        send_user(me, "%c%s", '!', "���Ѿ�����ǮƱ�ˡ�");
                        return;
                }
                if( sizeof_inventory(me, 1, MAX_CARRY) >= MAX_CARRY )
                {
                        send_user(me, "%c%s", '!', "��Я���Ķ���̫���ˡ�");
                        return;
                }
                level = me->get_level();
                gold = 50000;
                if (orgnpc->get_gold()<gold)
                {
                        send_user(me, "%c%s", '!', "�����ʽ��㣬�޷����̡�");
                        return;
                }
                if (flag==30)
                {
			result = sprintf("%s��\n    �������еĴ�С�����벻����Ǯ�Ŀ�����������˵Ĵ����Ǳز����ٵġ����ţ�����%d�����Ʊ������һ�������˵�ͷ�ԣ��汾��׬%d��Ǯ�����ɣ�\n", who->get_name(), gold, gold/2);
			result += sprintf(ESC"��������\ntalk %x# info.31\n", getoid(who));
			result += sprintf(ESC"�뿪\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			break;
		}
                orgnpc->add_gold(-gold);
                item = new("/item/std/0002");
                item->set_orgin_money(gold);
                item->set_money(gold);
                if( p = item->move(me, -1) ) item->add_to_user(p);
                else destruct(item);
                me->set_save_2("orgtask3.type", 1);
                me->set_save_2("orgtask3.money", gold);
		if ( me->get("tasklist") != 0 )
		{
			send_user( me, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"��������" );
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 20, "��������" );
		}
                break;
	case 40:
	case 41:
		item = present("ǮƱ", me, 1, MAX_CARRY*4);
		if (!objectp(item)||item->get_money()<item->get_orgin_money()*3/2)
		{
			result = sprintf("%s��\n    ��ξ��̣����Ҫ�����Խ��ˡ�ÿ�����Ҷ���һ��ר��������Ʒ�ĵ��ز�Ʒ���ˣ�������ȥ��������Ҫ�Ƚ�һ�¸���֮���ز�Ʒ����۲��죬���������������򵥵����⾭�ˡ�\n", who->get_name());
			result += sprintf(ESC"�뿪\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
                if (flag==40)
                {
			result = sprintf("%s��\n    �������ҹ�Ȼû�����ˡ����ȷ�Ǹ����̵���š�������һ�����������ľ������˱ض���Խ��Խǿʢ��\n", who->get_name() );
			result += sprintf(ESC"�������\ntalk %x# info.41\n", getoid(who));
			result += sprintf(ESC"�뿪\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			break;
		}
		orgnpc->add_gold(item->get_money());
		FAMILY_D->org_channel( name, 0, sprintf( HIR "��������%sΪ����׬ȡ��%d��",
                	me->get_name(), item->get_money()- item->get_orgin_money() ) );
		gold = me->get_level()*100;
		gold = gold * me->get_online_rate()/100;
		contrib = me->get_level()/4;
		contrib = contrib * me->get_online_rate()/100;
		exp = NPC_ENERGY_D->get_exp_bonus(me->get_level())*32;
		exp = exp * me->get_online_rate()/100;
		result = "������˰��ɾ�������";
		if (random(100)<10* me->get_online_rate()/100)
		{
			switch(random(3))
			{
			case 0: gold *= 2; result += HIR"�������Ľ�������Ǯ�ӱ���"BLK;break;
			case 1: contrib *= 2; result += HIR"�������Ľ������ﹱ�ӱ���"BLK;break;
			case 2: exp *= 2; result += HIR"�������Ľ���������ӱ���"BLK;break;
			}

		}
		me->add_exp(exp);
		me->add_cash(gold);
		me->log_money("��������", gold);
		"/sys/sys/count"->add_income("orgtrader", gold);
		number = me->get_number();
		orgnpc->set_member_contribute(number, orgnpc->get_member_contribute(number)+contrib);
		result += sprintf("��������%d�����ɹ��׶�����%d����ý�Ǯ%d��\n", exp, contrib, gold);
		send_user( me, "%c%s", ';', result );
		send_user( me, "%c%d", 0x2d, getoid(item) );
                destruct(item);
                me->delete_save_2("orgtask3");
		send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 20,"" );
		send_user( me, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"" );

		break;
	}
}

// ���ɵ����Ժ��
void do_look_5(object me, object who )
{
	string result, name;
	int position, store;
	object orgnpc;
	result = sprintf("%s��\n    ���Ǹ����������ɼ��ܿ��������ԺԺ������֪�������Һ�Ҫ�£�\n", who->get_name());
	position = me->get_org_position();
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	if (position>0 && me->get_org_name()==name)
	{
		result += sprintf(ESC"ѧϰ����\ntalk %x# skill\n", getoid(who));
		if (position>=8)
		{
			result += sprintf(ESC"�о�����\ntalk %x# info.10\n", getoid(who));
		}
		result += sprintf(ESC"�˽⵱ǰ���ɼ������\ntalk %x# info.20\n", getoid(who));
	}
	result += sprintf(ESC"�뿪\nCLOSE\n");
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
}

// ���Ժ������غ���
void do_info_5(object me, object who, string arg )
{
	int position, flag, number, i, size, level, time, degree, speed, len, *search;
	string result, name, list, *key;
	object orgnpc, city, *char, item, file;
	mapping skls;
	position = me->get_org_position();
	flag = to_int(arg);
	name = me->get_org_name();
	if (position==0 || name=="" || name!=who->get_org_name()) return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	skls = orgnpc->get_skill_dbase();
	size = 0;
	number = sizeof(skls);
	key = keys(skls);
	for (i=0;i<number;i++)
	{
		if (orgnpc->get_skill(to_int(key[i]))>1) size++;
	}
	switch(flag)
	{
	case 10:
	case 11:
		if (position<8) return;
		if (orgnpc->get_science()>=orgnpc->get_grade()*4)
		{
			result = sprintf("%s��\n    ���ڱ�����о����Ѿ��ﵽ��%d������ޣ��޷��������ˡ����˻��Ƕ���עһ�°��ɵ���������ɡ�\n", who->get_name(), orgnpc->get_grade()*4);
			result += sprintf(ESC"�뿪\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		time = orgnpc->get_sciencetime();
		if (time>0)
		{
			if (time()>time)
			{
				orgnpc->add_science(1);
				orgnpc->set_sciencetime(0);
				char = orgnpc->get("comrade");
				if (char && sizeof(char)>0)
				{
					for (i=0;i<sizeof(char);i++)
						char[i]->set_level(orgnpc->get_science());
				}
				orgnpc->save();
				FAMILY_D->org_channel( name, 0, sprintf( HIR "�������Ժ�Ĳ�иŬ���������о���˳��������1�㣬�ְ��ɵ��о���Ϊ%d��",
                                         orgnpc->get_science() ) );
			}
			else
			{
				result = sprintf("%s��\n    ����ȫ���Ժ����һ����ץ���԰��ɿƼ����о�����������ֻ���ٵȴ�%d���Ӿ�һ�����Կ����о��ĳɹ��ˡ�\n", who->get_name(), (time - time())/60);
				result += sprintf(ESC"�뿪\nCLOSE\n");
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return;
			}
		}
		if (flag==10)
		{
			result = sprintf("%s��\n    ����1���о�����Ҫ����300������ʽ��100�㴢���������ʱʮ�롣�Ƿ������о�����\n", who->get_name() );
			result += sprintf(ESC"ȷ��\ntalk %x# info.11\n", getoid(who));
			result += sprintf(ESC"ȡ��\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		}
		else
		{
			if (orgnpc->get_gold()<3000000 || orgnpc->get_store()<100)
			{
				result = sprintf("%s��\n    ���ڰ��е��ʽ�ʹ���ʮ�ֲ��㣬����������ɼ��ܵ��о��������������˶�����ư��еĲ�����\n", who->get_name() );
				result += sprintf(ESC"�뿪\nCLOSE\n");
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			}
			else
			{
				orgnpc->add_gold(-3000000);
				orgnpc->set_store(orgnpc->get_store()-100);
				orgnpc->set_sciencetime(time()+1*10);
				orgnpc->save();
				result = sprintf("%s��\n    ����ȫ���Ժ����һ����ץ���԰��ɿƼ����о�����������ֻ���ٵȴ�ʮ���һ�����Կ����о��ĳɹ��ˡ�\n", who->get_name() );
				result += sprintf(ESC"�뿪\nCLOSE\n");
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			}
		}
		break;
	case 20:
		result = sprintf("%s��\n    ��ǰ���ɵ��о���Ϊ%d���Ѿ��о��ļ���Ϊ%d��������ͬʱ�о��ļ�����������Ϊ%d����\n", who->get_name(), orgnpc->get_science(), size, 1 + orgnpc->get_science()/5 );
		len = strlen(result);
		i = orgnpc->get_research();
		if (i>0 && objectp(file = load_object(sprintf("/skill/%02d/%04d", i/100, i))))
		{
			result += sprintf("��ǰ�о�������%s��", file->get_name());
			switch(orgnpc->get_research_level())
			{
			case 1: list = "����";break;
			case 2: list = "�ӿ�";break;
		       default: list = "����";break;
			}
			speed = 400 + orgnpc->get_research_level()*400;
			result += "������" + list + "���ٶ��о��У�";
			level = orgnpc->get_skill(i);
			degree = orgnpc->get_skill_degree(i);
			level++;
			result += sprintf("����%dСʱ���������һ����\n", (level*level*5 - degree)/speed +1);
		}
		skls = orgnpc->get_researchs();
		search = keys(skls);
		size = sizeof(search);
		if (size>0)
		{
			for (i=0;i<size;i++)
			{
				if (search[i]>0 && objectp(file = load_object(sprintf("/skill/%02d/%04d", search[i]/100, search[i]))))
				{
					result += sprintf("    ��ǰ�о���"HIR"%s"NOR"��", file->get_name());
					switch(skls[search[i]])
					{
					case 1: list = "����";break;
					case 2: list = "�ӿ�";break;
				       default: list = "����";break;
					}
					speed = 400 + skls[search[i]]*400;
					result += "������" + list + "���ٶ��о��У�";
					level = orgnpc->get_skill(search[i]);
					degree = orgnpc->get_skill_degree(search[i]);
					level++;
					result += sprintf("����%dСʱ���������һ����\n", (level*level*5 - degree)/speed +1);
				}				
			}
		}
		if (len==strlen(result)) result += "��ǰû���о����ܡ�\n";
		result += sprintf(ESC"�뿪\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	}
}

// ���ɵ����Ժ��
void do_look_6(object me, object who )
{
	string result, name, *list;
	int position, store, p, i, size, count;
	object orgnpc, item;
	result = sprintf("%s��\n    �Ҿ������Ժ��Ժ����ÿ��ʮ����Ͷ�ʮ�ĵ������ﶼ�����һЩ��Ʒ��ֻҪ����Ĺ�ģԽ׳��������������ƷƷ�ʱ��Խ�ߡ���ô���ǲ�������Щʲô��\n", who->get_name());
	position = me->get_org_position();
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	// ����Ƿ����������ʱ��
	who->check_item();
	list = orgnpc->get_productfile2();
	if (position>=ORG_TANGZHU && me->get_org_name()==name)
	{
		size = sizeof(list);
		if (size==0)
		{
			if (orgnpc->get_stable()<1000)
			{
				result += ESC"���ɰ����Ȳ��㣬�޷�������\nCLOSE\n";
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return;
			}
			result += ESC"��Ʒ�������\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		count = 0;
		for (i=0;i<size;i++)
		{
			if (list[i]!="")
			{
				result += sprintf(ESC"����%d����%s\ntalk %x# info.%d\n", 20000* orgnpc->get_grade(), list[i]->get_name(), getoid(who), i+1);
				count ++;
			}
		}
		if (count==0) 
		{
			count = orgnpc->get_buytime();
			if (count)
				result += sprintf(ESC"��Ʒ����%s�������\nCLOSE\n", short_time(count) );
			else
				result += ESC"��Ʒ�������\nCLOSE\n";
		}
		else result += sprintf(ESC"�뿪\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}

	result += sprintf(ESC"�뿪\nCLOSE\n");
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
}

// ���ɵ����Ժ��
void do_info_6(object me, object who, string arg )
{
	string result, name, *list;
	int position, store, p, i, size;
	object orgnpc, item;
	position = me->get_org_position();
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	position = me->get_org_position();
	if (position<1||name!=me->get_org_name())
	{
		return;
	}
	if ( position<ORG_TANGZHU)
	{
		return;
	}
	list = orgnpc->get_productfile2();
	size = sizeof(list);
	if (size==0)
	{
		return;
	}
	i = to_int(arg);
	if (i<1||i>size) return;
	i --;
	if (list[i]=="") return;
	if (me->get_cash()<orgnpc->get_grade()*20000)
        {
                notify( "�����ֽ��㡣" );
                return ;
        }
        me->add_cash(-orgnpc->get_grade()*20000);
        me->log_money("���ɲ�Ʒ����", -orgnpc->get_grade()*20000);
        "/sys/sys/count"->add_use("orgbuy", orgnpc->get_grade()*20000);
	item = new (list[i]);
	if (!item) return;
        if( USER_INVENTORY_D->can_carry( me, item )  < 1 )
        {
                notify( "��Я���Ķ���̫���ˡ�" );
                destruct(item);
                return ;
        }
        notify( sprintf("��������%s", item->get_name()) );
        if( p = item->move(me, -1) )
        {
                item->add_to_user(p);
        }
        else
        	destruct(item);
        list[i] = "";
        orgnpc->set_productfile2(list);
        orgnpc->set_buytime(time());
        orgnpc->save();
}

// �������ɹ�ģ
void do_upgrade(object me, object who, string arg )
{
	string result, name;
	int position, grade, stable, favour, store, gold, time;
	object orgnpc, war;
	position = me->get_org_position();
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	if (name!=me->get_org_name()) return;
	if ( position<9 ) return;
	grade = orgnpc->get_grade();
	if (grade>=5) return;
	switch(grade)
	{
	case 1: stable = 1; break;
	case 2: stable = 2; break;
	case 3: stable = 3; break;
	case 4: stable = 4; break;
	}
	favour = stable;
	store = grade * 300;
	gold = 2000000*grade;
	time = orgnpc->get_gradetime();
	if (time>0)
	{
		if (time <time())
		{
			orgnpc->set_gradetime(0);
			orgnpc->set_grade(grade+1);
			FAMILY_D->org_channel( name, 0, sprintf( HIR "���ɹ�ģ����1���ְ��ɵĹ�ģΪ%d��",
				grade + 1 ) );
		}
		else
		{
			result = sprintf("%s��\n    ��ģ������ʣ��%d���ӡ�\n", who->get_name(), (time-time())/60);
			result += sprintf(ESC"�뿪\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return ;
		}
	}
	if (arg==""||arg==0)
	{
		result = sprintf("%s��\n    ��ǰ��İ��ɹ�ģΪ%d��������һ����ģ�䰲�����������ȶ�����ﵽ%d��������Ҫ����%d�㴢����%d�ʽ𣬾���������ģ�󣬱����������ֻ��Ҫվ1-3���Ӻ����˳�����������ģ�ˡ�����ע����ǣ�һ������ʧ�ܣ��������������������н�Ǯ�����ǲ��᷵�������ġ���ȷ��Ҫ�������ɹ�ģ��\n", who->get_name(), grade, favour, store, gold);
		result += sprintf(ESC"ȷ��\ntalk %x# upgrade.1\n", getoid(who));
		result += sprintf(ESC"ȡ��\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (orgnpc->get_gradewartime())
	{
		stable = (orgnpc->get_gradewartime()- time())/60;
		result = sprintf("%s��\n    ����%d���Ӻ�������ܵ�������������֣�����ܳɹ����˹��ʮ������˳�����������ģ�ˡ�\n", who->get_name(), stable);
		result += sprintf(ESC"�뿪\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (orgnpc->get_stable()<stable)
	{
		result = sprintf("%s��\n    ���ɰ����Ȳ���%d����ʱ�޷�������ģ��\n", who->get_name(), stable);
		result += sprintf(ESC"�뿪\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (orgnpc->get_favour()<favour)
	{
		result = sprintf("%s��\n    ���������Ȳ���%d����ʱ�޷�������ģ��\n", who->get_name(), favour);
		result += sprintf(ESC"�뿪\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (orgnpc->get_store()<store)
	{
		result = sprintf("%s��\n    ���ɴ�������%d����ʱ�޷�������ģ��\n", who->get_name(), store);
		result += sprintf(ESC"�뿪\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (orgnpc->get_gold()<gold)
	{
		result = sprintf("%s��\n    �����ʽ���%d����ʱ�޷�������ģ��\n", who->get_name(), gold);
		result += sprintf(ESC"�뿪\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (MAIN_D->get_host_type()==2)
	{
		orgnpc->set_store(orgnpc->get_store()-store);
		orgnpc->set_gold(orgnpc->get_gold()-gold);
		orgnpc->set_gradetime(time()+1*10);
		orgnpc->save();
		FAMILY_D->org_channel( name, 0, HIR "�������Ѿ���ʼ���д��ģ����������ʱΪʮ�롣" );
		return;
	}
	war = new ("/inh/std/upgrade");
	if (war)
	{
		orgnpc->set_store(orgnpc->get_store()-store);
		orgnpc->set_gold(orgnpc->get_gold()-gold);
		orgnpc->set_gradewartime(time()+600);
		orgnpc->set_wardamage(0);
		orgnpc->save();
		war->set_org_name(name);
		war->set_z(orgnpc->get("z"));
		war->set_grade(orgnpc->get_grade());
//		war->add_heart_sec(500);
		FAMILY_D->org_channel( name, 0, HIR "�������Ѿ���ʼ���д��ģ�������������ٹ�10����֮�󱾰����ܵ���һ����������֣���������г�Ա�������÷�����׼����" );
	}
}

// �����ܹܵ�����Ժ����
void do_quest(object me, object who, string arg )
{
	int position, flag, number, i, size, level, count, gold, p, type, x, y, z, order, exp, pot, cash;
	string result, name, list;
	object orgnpc, city, *char, item, file, npc;
	object *inv;
	position = me->get_org_position();
	flag = to_int(arg);
	name = me->get_org_name();
	if (position==0 || name=="" || name!=who->get_org_name()) return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	number = me->get_number();
	switch(flag)
	{
	case 10:
		if (me->get_save_2("orgtask2.type")!=0)
		{
			result = sprintf("%s��\n    �������Ժ����û����ɣ�������ȡ������\n", who->get_name());
			result += sprintf(ESC"�뿪\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (time()-me->get_save_2("orgtask2.time")<180)
		{
			result = sprintf("%s��\n    ����Ҫϸ�ģ���Ҫ��֮�����������¶��и��³̣�����ȥ�쿴һ�°�������������������ʲô�ɲ���ȥ��ġ�\n", who->get_name());
			result += sprintf(ESC"�뿪\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		result = sprintf("%s��\n    ����������񷱶࣬��Ϊ�����Ա���㣬һ��Ҫά����������������棬������һЩ����Ҫ��ǲ��ȥ������һ��Ҫ���ľ���ȥ��ɡ�\n", who->get_name());
		result += sprintf(ESC"����\ntalk %x# quest.11\n", getoid(who));
		result += sprintf(ESC"�뿪\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 11:
		if (me->get_save_2("orgtask2.type")!=0)
		{
			result = sprintf("%s��\n    �������Ժ����û����ɣ�������ȡ������\n", who->get_name());
			result += sprintf(ESC"�뿪\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (time()-me->get_save_2("orgtask2.time")<180)
		{
			result = sprintf("%s��\n    ��ȡ�µ�����Ժ������Ҫ��������ӡ�\n", who->get_name());
			result += sprintf(ESC"�뿪\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		type = 1+random(6);
		if (is_god(me))
		{
			if (me->get("lb")) type = me->get("lb");
		}
		send_user( me, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"��������" );
		if (type==2) type = 1;
		switch(type)
		{
		case 1:
			npc = new ("/npc/org/0100");
			npc->set("user", me->get_number());
			npc->set_name(name+"�Ų�");
			z = 10*(1+random(8));
			p = get_xy_point(z, IS_CHAR_BLOCK);
			if (!p) return;
			npc->add_to_scene(z, p / 1000, p % 1000, 3);
			file = load_object(sprintf("/map/map/%03d", z));
			result = sprintf("%s��\n    %s�Ų��ڣ�%s��%d, %d�������⵽�аﰵ�㣬�������б���Ļ����鱨����ǰȥ��������ҩ�͵�%s�Ų����У�ȷ�����ܰ�ȫ�ذ\n", who->get_name(), name, file->get_name(), get_x(npc), get_y(npc), name );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			me->set_save_2("orgtask2.place", file->get_name());
			me->set_save_2("orgtask2.x", get_x(npc));
			me->set_save_2("orgtask2.y", get_y(npc));
			me->set_2("orgtask2.npc", npc);
			item = new ("/item/01/0003");
                        if( p = item->move(me, -1) )
                        {
                                item->add_to_user(p);
                        }
                        else    destruct(item);
                        send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 1, "��Σ�ȼ�" );
			break;
		case 2:
			npc = new ("/npc/org/0101");
			npc->set("user", me->get_number());
			npc->set_owner(me);
			size = sizeof(task2);
			i = random(size);
			npc->set_name(sprintf("%s�ĺ���(%d)", task2[i], me->get_number()));
			me->set_save_2("orgtask2.name", task2[i]);
			me->set_save_2("orgtask2.id", sprintf("%x#", getoid(npc)));
			me->set_2("orgtask2.npc", npc );
	                z = get_z(who);  x = get_x(who);  y = get_y(who);
	                if( p = get_valid_xy(z, x, y, IS_CHAR_BLOCK) )
	                {
	                        x = p / 1000;  y = p % 1000;
	                        npc->add_to_scene( z, x, y, 3 );
	                }
			result = sprintf("%s��\n    ����һλ��Ա�����һ����·�ĺ�ͯ������������%s�ĺ��ӣ�Ϊ�˸�úͰ��յĹ�ϵ�����ȥ��%s�ĺ����ͻ�ȥ��\n", who->get_name(), task2[i], task2[i] );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 2, "��·�ĺ�ͯ" );
			break;
		case 3:
			npc = new ("/npc/org/0102");
			npc->set("user", me->get_number());
			npc->set_name(name+"�ı���");
			z = 10*(1+random(8));
			p = get_xy_point(z, IS_CHAR_BLOCK);
			if (!p) return;
			npc->add_to_scene(z, p / 1000, p % 1000, 3);
			file = load_object(sprintf("/map/map/%03d", z));
			result = sprintf("%s��\n    ����һ����Ҫ������ʧ��%s�ģ�%d,%d��λ�ô����Ǽ������ϵ�������������������ϣ���㾡���ܽ��Ǽ�����Ѱ�ء�\n", who->get_name(), file->get_name(), get_x(npc), get_y(npc) );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			me->set_save_2("orgtask2.place", file->get_name());
			me->set_save_2("orgtask2.x", get_x(npc));
			me->set_save_2("orgtask2.y", get_y(npc));
			me->set_save_2("orgtask2.id", sprintf("%x#", getoid(npc)));
			me->set_2("orgtask2.npc", npc);
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 3, "Ѱ����ʧ�ı���" );
			break;
		case 4:
			size = sizeof(task2);
			i = random(size);
			me->set_save_2("orgtask2.name", task2[i]);
			result = sprintf("%s��\n    �����һλ��������˼���Լ�������%s��Ϊ���ȶ����ڵľ��ģ����ڲ��㽫�������͵������������С�\n", who->get_name(), task2[i] );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			item = new ("/item/01/0005");
                        if( p = item->move(me, -1) )
                        {
                                item->add_to_user(p);
                        }
                        else    destruct(item);
                        send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 4, "ǧ���ͼ���" );
			break;
		case 5:
			size = sizeof(food);
			i = random(size);
			me->set_save_2("orgtask2.name", food[i]);
			result = sprintf("%s��\n    �������±Ƚ�̫ƽ��û��̫��Ķ����������ʱ����Ͽ�������ռ�1��%s���Ա�����Ӧ��֮�衣\n", who->get_name(), food[i] );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 5, "������ʳ" );
			break;
		case 6:
			npc = new ("/npc/org/0103");
			npc->set("user", me->get_number());
			npc->set("target", me->get_name());
			npc->init_level(me->get_level());
			z = 10*(1+random(8));
			p = get_xy_point(z, IS_CHAR_BLOCK);
			if (!p) return;
			npc->add_to_scene(z, p / 1000, p % 1000, 3);
			file = load_object(sprintf("/map/map/%03d", z));
			result = sprintf("%s��\n    ����������֮��������߽���һ��Ҫ�������塣��������и�%s������%s��%d,%d����Σ�����գ���ǰȥ����������\n", who->get_name(), npc->get_name(), file->get_name(), get_x(npc), get_y(npc) );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			me->set_save_2("orgtask2.place", file->get_name());
			me->set_save_2("orgtask2.name", npc->get_name());
			me->set_save_2("orgtask2.x", get_x(npc));
			me->set_save_2("orgtask2.y", get_y(npc));
			me->set_2("orgtask2.npc", npc);
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 6, "�������" );
			break;
		}
		me->set_save_2("orgtask2.type", type);
		me->set_save_2("orgtask2.status", 1);
		me->set_save_2("orgtask2.time", time());
		break;
	case 20:
	case 21:
		switch(me->get_save_2("orgtask2.type"))
		{
		case 3:
			item = present("��ʧ�ı���", me, 1, MAX_CARRY*4);
			if (!objectp(item))
			{
				result = sprintf("%s��\n    ��ǲ����¿ɷ���ɡ�����Ҫ͵��Ŷ������������֪���󣬶������������㡣��󱾰��ǰ���ÿ����Ա�����Σ�ϣ�����μǡ�\n", who->get_name() );
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return;
			}
			break;
		case 5:
			list = me->get_save_2("orgtask2.name");
			inv = all_inventory(me, 1, MAX_CARRY*4);
			inv -= ({ 0});
			count = 0;
			for( i = 0, size = sizeof(inv); i < size; i ++ )
			{
				if ( inv[i]->get_name()==list)
				{
					if (inv[i]->get_max_combined()<=1) count ++;
					else count += inv[i]->get_amount();
				}
			}
			if (count<1)
			{
				result = sprintf("%s��\n    ��ǲ����¿ɷ���ɡ�����Ҫ͵��Ŷ������������֪���󣬶������������㡣��󱾰��ǰ���ÿ����Ա�����Σ�ϣ�����μǡ�\n", who->get_name() );
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return;
			}
			break;
		default:
			result = sprintf("%s��\n    ��ǲ����¿ɷ���ɡ�����Ҫ͵��Ŷ������������֪���󣬶������������㡣��󱾰��ǰ���ÿ����Ա�����Σ�ϣ�����μǡ�\n", who->get_name() );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return ;
		}
		if (flag==20)
		{
			result = sprintf("%s��\n    ���������ķǳ��á���%s�������������֣��Ժ����۰Ը���֮�ף��һ������������Ĺ��ͣ��������صĽ����㡣\n", who->get_name(), name );
			result += sprintf(ESC"�������\ntalk %x# quest.21\n", getoid(who));
			result += sprintf(ESC"�뿪\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		order = me->get_save_2("orgtask2.order");
		order ++;
		level = me->get_level();
		exp = (level*8+order*order*level*4)*3/5;
		exp = exp * me->get_online_rate()/100;
		pot = order*10+level;
		pot = pot * me->get_online_rate()/100;
		cash = (500+level*6*(order-1))*3/6;
		cash = cash * me->get_online_rate()/100;
		switch(me->get_save_2("orgtask2.type"))
		{
		case 3:
			send_user( me, "%c%d", 0x2d, getoid(item) );
                        destruct(item);
                        orgnpc->set_member_contribute(number, orgnpc->get_member_contribute(number)+1+order*2/9);
			orgnpc->add_stable(1);
			orgnpc->add_favour(1);
			me->add_potential(pot);
			me->add_cash(cash);
			me->add_exp(exp);
                        me->log_money("��������", cash);
                        "/sys/sys/count"->add_income("org", cash);
                        send_user(me, "%c%s", ';', sprintf("���þ���%d��Ǳ��%d����Ǯ%d���ﹱ������%d�����ɵ���������1�㡢��������1�㡣", exp, pot, cash, 1+order*2/9) );
                        me->delete_save_2("orgtask2");
                        me->delete_2("orgtask2");
                        if (order>=10)
                        {
                        	order = 0;
                        	if (random100()<5*me->get_online_rate()/100) "/quest/box"->give_box(me);
                        }
                        me->set_save_2("orgtask2.order", order);
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 3,"" );
			send_user( me, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"" );
			break;
		case 5:
			count = 1;
			for( i = 0, size = sizeof(inv); i < size; i ++ )
			{
				if ( inv[i]->get_name()==list)
				{
					if (inv[i]->get_max_combined()<=1)
					{
						count --;
						send_user( me, "%c%d", 0x2d, getoid(inv[i]) );
	                                	destruct(inv[i]);
					}
					else
					{
						if (count > inv[i]->get_amount())
						{
							count -= inv[i]->get_amount();
							send_user( me, "%c%d", 0x2d, getoid(inv[i]) );
	                                		destruct(inv[i]);
						}
						else
						{
							inv[i]->add_amount( -count );
							count = 0;
						}
					}
					if (count<=0) break;
				}
			}
                        orgnpc->set_member_contribute(number, orgnpc->get_member_contribute(number)+1+order*2/9);
			orgnpc->add_stable(2);
			orgnpc->add_favour(2);
			me->add_potential(pot);
			me->add_cash(cash);
			me->add_exp(exp);
                        me->log_money("��������", cash);
                        "/sys/sys/count"->add_income("org", cash);
                        send_user(me, "%c%s", ';', sprintf("���þ���%d��Ǳ��%d����Ǯ%d���ﹱ������%d�����ɵ���������2�㡢��������2�㡣", exp, pot, cash, 1+order*2/9));
                        me->delete_save_2("orgtask2");
                        me->delete_2("orgtask2");
                        if (order>=10)
                        {
                        	if (random100()<5*me->get_online_rate()/100) "/quest/box"->give_box(me);
                        	order = 0;
                        }
                        me->set_save_2("orgtask2.order", order);
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 5,"" );
			send_user( me, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"" );
			break;
		}
		break;
	case 30:
		if (position!=9) return;
		if (time()>orgnpc->get_demisstime()) return;
		result = sprintf("%s��\n    ����ȡ���������ã�ȷ����\n", who->get_name() );
		result += sprintf(ESC"ȷ��\ntalk %x# quest.31\n", getoid(who));
		result += sprintf(ESC"�뿪\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 31:
		if (position!=9) return;
		if (time()>orgnpc->get_demisstime()) return;
		orgnpc->set_demissnumber(0);
		orgnpc->set_demisstime(0);
		orgnpc->save();
	        FAMILY_D->org_channel( name, 0, sprintf( HIR "����%s�����������ǣ����վ���������λ��",
	                who->get_name() ) );
		break;
	}

}

void init_org_place(int z, string name, object orgnpc)
{
	object npc, *all;
	int i;
	int * locate = ({ 87, 123 , 95, 129 , 95, 117 , 107, 126, 121, 111, 110, 102, 86, 140, 77, 134,  });

	npc = new ("/npc/org/0010");
	npc->set_org_name(name);
	npc->set_name(name+"�ܹ�");
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 79, 141, 2);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	npc = new ("/npc/org/0011");
	npc->set_org_name(name);
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 67, 134, 2);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	npc = new ("/npc/org/0012");
	npc->set_org_name(name);
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 114, 152, 2);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	npc = new ("/npc/org/0013");
	npc->set_org_name(name);
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 58, 110, 2);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	npc = new ("/npc/org/0014");
	npc->set_org_name(name);
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 67, 104, 6);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	npc = new ("/npc/org/0015");
	npc->set_org_name(name);
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 110, 88, 2);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	npc = new ("/npc/org/0016");
	npc->set_org_name(name);
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 139, 110, 2);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	npc = new ("/npc/org/qgl_amass");
	npc->set_org_name(name);
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 82, 139, 3);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	all = ({ });
	// ����
	for (i=0;i<8;i++)
	{
		npc = new ("/npc/org/0017");
		npc->set_org_name(name);
		npc->set("orgnpc", orgnpc);
		npc->set_level(orgnpc->get_science());
		npc->add_to_scene(z, locate[2*i], locate[2*i+1], 2);
		set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
		all += ({ npc });
	}
	orgnpc->set("comrade", all);
}

void task_giveup(object player, int type)
{
	int time;
	object npc;
	if (type==20) return;		// ���̲��ܷ���
	send_user( player, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, type, "" );
	send_user( player, "%c%c%c%w%s", 0x51, 1, 1, TID_ORG, "" );
	if (type<10)
	{
		switch(type)
		{
		case 1:
		case 2:
		case 3:
		case 6:
			npc = player->get_2("orgtask2.npc");
			if (objectp(npc))
			{
		                npc->remove_from_scene();
		                destruct(npc);
			}
			break;
		}
		time = player->get_save_2("orgtask2.time");
		player->delete_save_2("orgtask2");
		player->set_save_2("orgtask2.time", time);
	}
	else
	if (type==10)
	{
		time = player->get_save_2("orgtask.time");
		player->delete_save_2("orgtask");
		player->set_save_2("orgtask.time", time);
	}
}

void send_task_list(object who)
{
	int type;
	if (who->get_save_2("orgtask.type")==0&&who->get_save_2("orgtask2.type")==0&&who->get_save_2("orgtask3.type")==0) return;
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"��������" );
	type = who->get_save_2("orgtask.type");
	if (type>0) send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 10, "��������" );
	type = who->get_save_2("orgtask2.type");
	switch(type)
	{
	case 1:
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 1, "��Σ�ȼ�" );
		break;
	case 2:
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 2, "��·�ĺ�ͯ" );
		break;
	case 3:
		if (who->get_save_2("orgtask2.status")==1)
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 3, "Ѱ����ʧ�ı���" );
		else
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 3, "�ͻ���ʧ�ı���" );
		break;
	case 4:
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 4, "ǧ���ͼ���" );
		break;
	case 5:
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 5, "������ʳ" );
		break;
	case 6:
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 6, "�������" );
		break;
	}
	type = who->get_save_2("orgtask3.type");
	if (type>0) send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 20, "��������" );
}

string get_task_str(object who, int iKind)
{
	string result, name, unit;
	int count, order, level;
	name = who->get_org_name();
	result = "";
	if (name=="") return result;
	order = who->get_save_2("orgtask2.order");
	level = who->get_level();
	switch(iKind)
	{
	case 1:
		result = sprintf(BLK"��Σ�ȼ�\n"BLK"��ǰ������%d/10\n"BLK"����Ŀ�ģ�\n"BLK"    ���ȸ��˵�%s�Ų������ҩ��ȫ���͵������С�\n"BLK"����������\n"BLK"    %s�Ų���%s�ģ�%d,%d�������⵽�аﰵ�㣬�������б���Ļ����鱨����ǰȥ��������ҩ�͵�%s�Ų����У�ȷ�����ܰ�ȫ�ذ\n"BLK"���������ﹱ%d��\n"BLK"          ����%d\n"BLK"          Ǳ��%d\n"BLK"          ��Ǯ%d\n", order+1, name, name, who->get_save_2("orgtask2.place"), who->get_save_2("orgtask2.x"), who->get_save_2("orgtask2.y"), name, 1+(order+1)*2/9, (level*8+(order+1)*(order+1)*level*4)*3/5, (order+1)*10+level, (500+level*6*order)*3/6 );
		break;
	case 2:
		name = who->get_save_2("orgtask2.name");
		result = sprintf(BLK"��·�ĺ�ͯ\n"BLK"��ǰ������%d/10\n"BLK"����Ŀ�ģ�\n"BLK"    ��%s�ĺ��Ӱ�ȫ���ͻ�%s���С�\n"BLK"����������\n"BLK"    ����һλ��Ա�����һ����·�ĺ�ͯ������������%s�ĺ��ӣ�Ϊ�˸�úͰ��յĹ�ϵ�����ȥ��%s�ĺ����ͻ�ȥ������ס��%s��%s��\n"BLK"���������ﹱ%d��\n"BLK"          ����%d\n"BLK"          Ǳ��%d\n"BLK"          ��Ǯ%d\n", order+1, name, name, name, name, "/quest/escort"->get_country_name(name), "/quest/escort"->get_place_name(name), 1+(order+1)*2/9, (level*8+(order+1)*(order+1)*level*4)*3/5, (order+1)*10+level, (500+level*6*order)*3/6 );
		break;
	case 3:
		result = sprintf(BLK"��ʧ�ı���\n"BLK"��ǰ������%d/10\n"BLK"����Ŀ�ģ�\n"BLK"    ����ʧ�ı���Ѱ��\n"BLK"����������\n"BLK"    ����һ����Ҫ������ʧ��%s�ģ�%d,%d��λ�ô����Ǽ������ϵ�������������������ϣ���㾡���ܽ��Ǽ�����Ѱ�ء�\n"BLK"���������ﹱ%d��\n"BLK"          ����%d\n"BLK"          Ǳ��%d\n"BLK"          ��Ǯ%d\n", order+1, who->get_save_2("orgtask2.place"), who->get_save_2("orgtask2.x"), who->get_save_2("orgtask2.y"), 1+(order+1)*2/9, (level*8+(order+1)*(order+1)*level*4)*3/5, (order+1)*10+level, (500+level*6*order)*3/6 );
		break;
	case 4:
		name = who->get_save_2("orgtask2.name");
		result = sprintf(BLK"ǧ���ͼ���\n"BLK"��ǰ������%d/10\n"BLK"����Ŀ�ģ�\n"BLK"    �������͸�%s��\n"BLK"����������\n"BLK"    �����һλ��������˼���Լ�������%s������ס��%s��%s��Ϊ���ȶ����ڵľ��ģ����ڲ��㽫�������͵������������С�\n"BLK"���������ﹱ%d��\n"BLK"          ����%d\n"BLK"          Ǳ��%d\n"BLK"          ��Ǯ%d\n", order+1, name, name, "/quest/escort"->get_country_name(name), "/quest/escort"->get_place_name(name), 1+(order+1)*2/9, (level*8+(order+1)*(order+1)*level*4)*3/5, (order+1)*10+level, (500+level*6*order)*3/6 );
		break;
	case 5:
		name = who->get_save_2("orgtask2.name");
		result = sprintf(BLK"������ʳ\n"BLK"��ǰ������%d/10\n"BLK"����Ŀ�ģ�\n"BLK"    �ռ�1��%s��\n"BLK"����������\n"BLK"    �������±Ƚ�̫ƽ��û��̫��Ķ����������ʱ����Ͽ�������ռ�1��%s���Ա�����Ӧ��֮�衣\n"BLK"���������ﹱ%d��\n"BLK"          ����%d\n"BLK"          Ǳ��%d\n"BLK"          ��Ǯ%d\n", order+1, name, name, 1+(order+1)*2/9, (level*8+(order+1)*(order+1)*level*4)*3/5, (order+1)*10+level, (500+level*6*order)*3/6 );
		break;
	case 6:
		name = who->get_save_2("orgtask2.name");
		result = sprintf(BLK"�������\n"BLK"��ǰ������%d/10\n"BLK"����Ŀ�ģ�\n"BLK"    ����%s��\n"BLK"����������\n"BLK"    ����������֮��������߽���һ��Ҫ�������塣��������и�%s������%s�ģ�%d,%d��Σ�����գ���ǰȥ����������\n"BLK"���������ﹱ%d��\n"BLK"          ����%d\n"BLK"          Ǳ��%d\n"BLK"          ��Ǯ%d\n", order+1, name, name, who->get_save_2("orgtask2.place"), who->get_save_2("orgtask2.x"), who->get_save_2("orgtask2.y"), 1+(order+1)*2/9, (level*8+(order+1)*(order+1)*level*4)*3/5, (order+1)*10+level, (500+level*6*order)*3/6 );
		break;
	case 10:
		name = who->get_save_2("orgtask.name");
		count = who->get_save_2("orgtask.count");
		unit = who->get_save_2("orgtask.unit");
		order = who->get_save_2("orgtask.order");
		result = sprintf(BLK"���Ӵ���\n"BLK"��ǰ������%d/10\n"BLK"����Ŀ�ģ�\n"BLK"    �չ�"HIR"%d%s%s"BLK"�����������ɵ��ʷ�������\n"BLK"����������\n"BLK"    ���ڰ������ڷ�չ���о���ά���Ĺ�ϵ����Ҫ���������Ĳ����Ա���ʱ֮�衣Ŀǰ����ȱ��"HIR" %s "BLK"����˰��е��ʷ�����ί���Ұ�æȥ��"HIR"%d%s%s"BLK"������\n"BLK"���������ﹱ%d��\n"BLK"          ����2000\n", order+1, count, unit, name, name, count, unit, name, order+1 );
		break;
	case 20:
		count = who->get_save_2("orgtask3.money");
		result = sprintf(BLK"���ɾ���\n"BLK"����Ŀ�ģ�\n"BLK"    ׬ȡ%d��󣬴��ظ����ɵ��ʷ�����\n"BLK"����������\n"BLK"    �������еĴ�С�����벻����Ǯ�Ŀ�����������˵Ĵ����Ǳز����ٵġ����ʷ��������еõ�һ��%d�����Ʊ��Ҫ�뷽�跨׬ȡ%d�����������С�\n"BLK"���������ﹱ%d��\n", count/2, count, count/2, who->get_level()/4 );
		break;
	}
	return result;
}

void upgrade(object me)
{
	string name, *all, *names, file, name2;
	object orgnpc;
	mapping skls;
	int level, contrib, store, i, size, skill, level2;
	name = me->get_org_name();
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	level = me->get_level();
	contrib = level * 12 / 10;
	if (level==10) store = 200;
	else
	if (level==20) store = 400;
	else
	if (level==25) store = 800;
	else
	if (level==30) store = 1200;
	else
	if (level>30)
	{
		switch((level-31)/5)
		{
		default:
			  store = 1200+((level-31)/5)*400; break;
		}
	}
	if (store>0)
	{
		skls = orgnpc->get_skill_dbase();
		size = sizeof(skls);
		all = ({ });
		names = sort_array( keys(skls), 1 );
		for (i = 0;i<size;i++)
		{		
			skill = to_int(to_int(names[i]));	
			if (skill==408||skill==409) continue;
			if (skill>=430 && skill<=438) continue;
			if (orgnpc->get_skill(skill)>1)
			{
				all += ({ names[i] });
			}
		}
		if (sizeof(all)==0) all = ({ "0109" });
		i = random(sizeof(all));
		skill = to_int(to_int(all[i]));
		level2 = orgnpc->get_skill(to_int(all[i]));
		orgnpc->improve_skill(to_int(all[i]), store);
		orgnpc->set_member_contribute(me->get_number(), orgnpc->get_member_contribute(me->get_number())+contrib);
		orgnpc->save();
		if( load_object( file = SKILL->get_skill_file(skill) ) && ( file->is_basic_skill()||file->is_vita_skill() ) )
			name2 = file->get_name();
		else
			name2 = all[i];
		if (level2<orgnpc->get_skill(to_int(all[i])))                       
                	FAMILY_D->org_channel( name, 0, sprintf( "��ϲ%s��%d���ȼ��ﵽ%d�������ɵ�"HIR" %s "NOR"������������%d�㡣"HIR" %s "NOR"������%d����",
                        	me->get_name(), me->get_number(), level, name2, store, name2, orgnpc->get_skill(to_int(all[i])) ) );
		else
 	               	FAMILY_D->org_channel( name, 0, sprintf( "��ϲ%s��%d���ȼ��ﵽ%d�������ɵ�"HIR" %s "NOR"������������%d�㡣",
        	                me->get_name(), me->get_number(), level, name2, store ) );
		                        	
		
	}
}
//����Ⱥ���ż�
void org_mail(int id,string cName, string info)
{
	int i,size,number;
	object orgnpc;
	string cTmp,*nName,account;
	if ( !stringp(info) || sizeof(info) == 0 )
		return ;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", cName ) );
	if (!objectp(orgnpc))
		return ;
	size = orgnpc->sizeof_member_dbase();
	nName = orgnpc->get_all_member();
	for(i=0;i<size;i++)
	{
		number = to_int(nName[i]);
		account = orgnpc->get_member_id(number);
		"/inh/user/mail"->sys_mail(account, number,info);
	}
}