
// �Զ����ɣ�/make/npc/make0007

#include <npc.h>
#include <cmd.h>
#include <ansi.h>
#include <item.h>

inherit OFFICER;

// ����������ʦ��
int is_repairer() { return 1; }

void do_welcome(string arg);
void do_identify(string arg);

// ��������ȡ��������
int get_char_picid() { return 5407; }

// ���������촦��
void create()
{
        set_name("������ϰ�");
        set_city_name("�ܹ�");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
                "identify"          : (: do_identify :),
        ]));
        setup();
}



// �������Ի�����
void do_look( object me )
{
	object who = this_object();
	"/quest/help"->send_help_tips(who, 52);
        if (me->get_skill(650))
	        send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
                        sprintf("%s��\n    %s\n��������Ҫʲô����\n"
                        ESC "��Ҫ����װ��\nrepair %x# identify\n"
                        ESC "��Ҫ�ֽ�װ��\nrepair * %x#\n"
                        ESC "����Ҫ��ͨ����\nrepair %x# 2\n"
                        ESC "��ֻ�Ǿ�����������\nCLOSE\n", who->get_name(), "/quest/word"->get_normal_word(who),  getoid(who), getoid(who), getoid(who) ) );
        else
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
                	sprintf("%s��\n    %s\n��������Ҫʲô����\n"
                	ESC "��Ҫ����װ��\nrepair %x# identify\n"
//                        ESC "����Ҫ��������������\nrepair %x# 1\n"
                        ESC "����Ҫ��ͨ����\nrepair %x# 2\n"
                        ESC "��ֻ�Ǿ�����������\nCLOSE\n", who->get_name(), "/quest/word"->get_normal_word(who),  getoid(who), getoid(who) ) );
}
/*
void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object who, string arg )
{
	int level;
	object me,*inv,item;
	string result;
	me = this_player();
	if (arg==0)
	{
//		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), sprintf("%s��\n    �ҿ��԰������δ������װ��������ÿ��װ��Ҫ��ȡ��һЩ�������ã���ֱ�ӽ�װ�������ҾͿ����ˡ�", who->get_name() ) );
		send_user( me, "%c%c%d", 0x61, 1, getoid(who) );
		return;
	}
	item = present(arg, me,	0, 0);
	if (!item) return;
        if( !item->is_equip() )
        {
                return 0;
        }
        if (item->get_item_type() == ITEM_TYPE_TALISMAN)
        {
        	return 0;
        }
        if (!item->get_hide())
        {
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
                	sprintf("%s��\n    %s�Ѿ��������ˡ�"
                        , who->get_name(), item->get_name() ) );
		return;
        }	
        level = item->get_level();
        level *= 30;
        if (level==0) level = 30;
        if (me->get_cash()<level)
        {
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
                	sprintf("%s��\n    ����ֽ���%d���޷�����%s��"
                        , who->get_name(), level, item->get_name() ) );
		return;        	
        }        
        me->add_cash(-level);
	me->log_money("����", -level);
	"/sys/sys/count"->add_use("����", level);   
	item->set_hide(0);
	level = get_d(item);
	item->add_to_user(level);     
	level = item->get_item_color();
	switch(level)
	{
	case 0:
		result = "���װ������ͨûʲô�ر�ġ�";
		break;
	case 1:
		result = "���װ������һ��������װ����";
		break;
	case 2:
		result = "����һ�����ѵõ�һ�����װ������ϲ�㡣";
		break;
	default:
		result = "����һ��ϡ����Ʒѽ�����������ܿ���������һ�����";
		break;
	}
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
                sprintf("%s��\n    %s\n"
                ESC "��������\ntalk %x# welcome\n"
                ESC "�뿪\nCLOSE\n"
		, who->get_name(), result, getoid(who) ) );
}

// ������������Ʒ
int accept_object( object me, object item ){ return __FILE__ ->accept_object_callout( this_object(), me, item ); }

// ������������Ʒ(���߸���)
int accept_object_callout( object who, object me, object item )
{
        int level;

        me->to_front_eachother(who);

        if( !item->is_equip() )
        {
                return 0;
        }
        if (item->get_item_type() == ITEM_TYPE_TALISMAN)
        {
        	return 0;
        }
        if (!item->get_hide())
        {
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
                	sprintf("%s��\n    %s�Ѿ��������ˡ�"
                        , who->get_name(), item->get_name() ) );
		return -99;
        }
        level = item->get_level();
        level *= 30;
        if (level==0) level = 30;
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
                sprintf("%s��\n    �������װ����Ҫ%d���Ƿ������Ҫ������\n"
                ESC "�ǵģ���Ҫ����\ntalk %x# welcome.%x#\n"
                ESC "̫���ˣ��Ҳ�������\nCLOSE\n", who->get_name(), level, getoid(who), getoid(item) ) );
	return -99;               
}

void do_identify( string arg )
{
        object me = this_object();
        __FILE__ ->do_identify2(me, arg);
}

void do_identify2( object who, string arg )
{
	int level;
	object me,*inv,item;
	string result;
	me = this_player();
	item = present(arg, me,	0, 0);
	if (!item) return;
        if( !item->is_equip() )
        {
                return;
        }
        if (item->get_item_type() == ITEM_TYPE_TALISMAN)
        {
        	return;
        }
        if (!item->get_hide())
        {
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
                	sprintf("%s��\n    %s�Ѿ��������ˡ�"
                        , who->get_name(), item->get_name() ) );
		return ;
        }
        level = item->get_level();
        level *= 30;
        if (level==0) level = 30;
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
                sprintf("%s��\n    �������װ����Ҫ%d���Ƿ������Ҫ������\n"
                ESC "�ǵģ���Ҫ����\ntalk %x# welcome.%x#\n"
                ESC "̫���ˣ��Ҳ�������\nCLOSE\n", who->get_name(), level, getoid(who), getoid(item) ) );
	send_user( me, "%c%c", 0x61, 0 );                
	return ;   
}
*/