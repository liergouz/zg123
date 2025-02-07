#include <ansi.h>
#include <npc.h>
#include <cmd.h>
#include <city.h>

inherit OFFICER;

// ������С��ʶ��
int is_seller() { return 1; }

int is_self_look() { return 1; }

// ��������ȡ��������
int get_char_picid() { return 9715; }

void do_welcome( string arg );
void do_look2( object me, object who );

// ���������촦��
void create()
{
	object me = this_object();
        set_name("���Ժ��");
        set_city_name("����");

        set_2( "good", ([
                "01" : "/item/std/0401",
                "02" : "/item/std/0498",
                "03" : "/item/std/0499",
//                "04" : "/item/std/0497",
                "05" : "/item/std/0413",
                "06" : "/item/std/0591",
                "07" : "/item/32/3231",
                "08" : "/item/91/9100",
                "09" : "/item/91/9101",
                "10" : "/item/91/9110",
                "11" : "/item/91/9111",
                "12" : "/item/stuff/0106",
        ]) );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
        setup();
}

void do_look( object who )
{
        string result;
        object me = this_object();
        __FILE__ ->do_look2(me, who);
}       

void do_look2( object me, object who )
{
	 string result;        
        if (me->get_org_name()==who->get_org_name())
        {
        	result = sprintf("%s��\n    ��ս�����Ϸ���Ϊ���ṩһ����������ʣ������Ϸ����ﻹ�ܿ����о��߼��Ĺ�����е����ô���Ƿ���Ҫ�Ϸ���Щʲô��\n", me->get_name());
        	result += sprintf(ESC "��������\nlist %x#\n", getoid(me) );
        	if (who->get_org_position()>=8)
        		result += sprintf(ESC "�о�ս������\ntalk %x# welcome.1\n", getoid(me) );
        }
        else return;
        result += ESC"�뿪\nCLOSE\n";
        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), result );
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object who, string arg )
{
	int flag, position, weapon;
	object me, orgnpc;
	string name, result;
	me = this_player();
	position = me->get_org_position();
	name = me->get_org_name();
	if (name=="") return;
	if (position<8 ) return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );		
	if (!objectp(orgnpc)) return;	
	weapon = orgnpc->get_weapon();
	if (weapon==1)
	{
		result = sprintf("%s��\n    ���ɵĹ�����е�Ѿ��о��ɹ���\n", who->get_name());
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return ;
	}
	if (weapon>1)
	{
		if (time() < weapon)
		{
			result = sprintf("%s��\n    ���ڱ�������ȫ������Ͷʯ�����о������У������ٵȴ�%d���ɼ����о��ɹ���\n", who->get_name(), weapon - time());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return ;		
		}
		else
		{
			remove_call_out( "weapon_callout" );
			orgnpc->set_weapon(1);
			result = "ս�������Ժ���Ѿ��ɹ�������ս�����ܼ�����";
			FAMILY_D->org_channel( name, 0, result);
			return;			
		}
	}
	flag = to_int(arg);
	switch(flag)
	{
	case 1:
		result = sprintf("%s��\n    ��ǰ�İ���ľ��" HIR "����Ϊ%d�������ʽ�Ϊ%d" NOR "���о�ս�����ܱ�������" HIR "500000�İ����ʽ�" NOR "��" HIR" 200��ľ�Ĵ���" NOR "���о��ɹ���������ͷ����ļս������Э��ս�����о���ʱΪ" HIR "300��" NOR "��\n    ��ȷ��Ҫ�о�ս��������\n", who->get_name(), orgnpc->get_wood(), orgnpc->get_gold());
		result += sprintf(ESC "ȷ��\ntalk %x# welcome.2\n", getoid(who) );
		result += ESC"ȡ��\nCLOSE\n";
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 2:
		if (orgnpc->get_gold()<500000)
		{
			result = sprintf("%s��\n    �����ʽ���500000���޷���ʼ�о���\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return ;	
		}
		if (orgnpc->get_wood()<200)
		{
			result = sprintf("%s��\n    ����ľ�Ĵ�������200���޷���ʼ�о���\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return ;	
		}		
		orgnpc->add_gold(-500000);
		orgnpc->add_wood(-200);
		orgnpc->set_weapon(time()+300);
		call_out("weapon_callout", 300, who);
		result = "ս�������Ժ����ʼ�з�ս�����ܼ�����";
		FAMILY_D->org_channel( name, 0, result);
		break;
	}
}

// ��������������(ѭ��)
void weapon_callout( object me )    // ÿ���ִ���
{
	string name, result;
	int weapon;
	object orgnpc;
        name = me->get_org_name();
        remove_call_out( "weapon_callout" );
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );	
	if (!objectp(orgnpc)) return;        
	weapon = orgnpc->get_weapon();
	if (weapon<=1) return;
	
	orgnpc->set_weapon(1);
	result = "ս�������Ժ���Ѿ��ɹ�������ս�����ܼ�����";
	FAMILY_D->org_channel( name, 0, result);
	
}