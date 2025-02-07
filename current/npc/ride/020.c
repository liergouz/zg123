
#include <npc.h>
#include <ansi.h>
#include <effect.h>
#include <task.h>
#include <equip.h>

inherit OFFICER;

string * name = ({ "С��", "����", "����", "����", "����", "��ë", "����",  });
string * city = ({ "��", "��", "��", "κ", "��", "��", "��", });

void do_welcome( string arg );

// ��������ȡ��������
int get_char_picid() { return 5402; } 

// ���������촦��
void create()
{
        set_name( "��������" );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));    
        setup();     
}

void do_look( object who )
{
	int z;
        object me = this_object();
        z = get_z(me);
        z = z/10;
        z -= 1;
        if (z<0||z>6) return;
        send_user( who, "%c%c%w%s", ':', 3, 5402,
        	sprintf("%s��\n    �벻����������%s����ר������%s�������磿ֻҪ���뱾�����Ѻù�ϵ�ﵽ���ܣ�������һ��6�������⾧ʯ���Ҷһ��������Ը���Ͼ��ܵõ������ˡ���ס���ܹ�����������������о�ʯ���Թ���\n"
                ESC "�һ����%s\ntalk %x# welcome.1\n"
                ESC "�ر�\nCLOSE\n", me->get_name(), city[z], name[z], name[z], getoid(me) ) );
}

void do_welcome( string arg )
{
        object who, me;
        string result;
        int flag, id;
        me = this_object();
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
        case 1:
        	result = me->get_name()+"��\n    �������á����衱ָ�����ʯ�����ҡ�\n";
                send_user( who, "%c%c%w%s", ':', 3, 5402, result );
                break;
	}
}

// ������������Ʒ
int accept_object( object who, object item ){ return __FILE__ ->accept_object_callout( this_object(), who, item ); }

// ������������Ʒ(���߸���)
int accept_object_callout( object me, object who, object item ) 
{
        int level, z;
        string result;
        object obj;

        me->to_front_eachother(who);
	
        if( !item->is_diamond_2() ) 
        {
                return 0;
        }
        if (item->get_level()!=6) 
        {
        	result = me->get_name()+"��\n    ������ľ�ʯ������������\n";
        	send_user( who, "%c%c%w%s", ':', 3, 5402, result );
        	return -99;
        }
        z = get_z(me);
        z = z/10;
        z -= 1;
        if (z<0||z>6) return 0;        
        if (who->get_city_name()!= city[z]+"��")
        {
        	result = me->get_name()+"��\n    �����Ǳ������ˣ����ܶһ���衣\n";
        	send_user( who, "%c%c%w%s", ':', 3, 5402, result );
        	return -99;
        }       
        item->remove_from_user();
        destruct( item );
        obj = new (sprintf("/item/ride/%03d", z+1));
        if (obj)
        {
		level = obj->move(who, -1);
                obj->add_to_user( level );        	
        }
        result = me->get_name()+"��\n    ���ڸ����һ�����ˡ�\n";
        send_user( who, "%c%c%w%s", ':', 3, 5402, result );
        return -99; 
}       