
#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <effect.h>

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 2100; }

// ���Լ���do_look����
int is_self_look() { return 1; }

// ���������촦��
void create()
{
        set_name("����ʯ");

        setup();
}

// �������Ի�����
void do_look( object who )
{

	if( who->get_legend(TASK_NEWBIE_03,7) && !who->get_legend(TASK_NEWBIE_03,8) && who->get_save_2("xuantieshi") < 3  )
	{
		if (get_effect(who, EFFECT_MINE)) return;
		send_user(who, "%c%c%w%s", 0x5a, 0, 10, "�����С���");
		set_effect(who, EFFECT_MINE, 10);
		who->set_save_2("mine",sprintf("%x#",getoid(this_object())));
	}

}

// �������Ի�����
void into_effect( object who )
{
	int p;
	object npc,item;
	
	send_user(who, "%c%c%c", 0x5a, 1, 1);
	npc = find_char(who->get_save_2("mine"));
	who->delete_save_2("mine");
	if ( !objectp(npc) )
		return;
	if( npc->get_name() == "����ʯ" && who->get_legend(TASK_NEWBIE_03,7) && !who->get_legend(TASK_NEWBIE_03,8) && who->get_save_2("xuantieshi") < 3  )
	{

		if ( objectp( item = present("����ʯ", who, 1, MAX_CARRY) ) && item->is_xuantieshi() == 1 ) 
		{
			if ( item->get_amount() < 3 )
				item->add_amount(1);
		}		
		else
		{
			item = new("item/98/0003");
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
				send_user(who,"%c%s",'!', "��Я���Ķ���̫����!");
				return;	
			}
			item->add_to_user(p);
		}
		npc->remove_from_scene();
		destruct(npc);
		send_user(who,"%c%s",'!', "��õ�"HIY"����ʯ");
		p = who->add_save_2("xuantieshi",1);
		if ( p >= 3 )
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,4,"���쾪��֮��(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_CHUGUO,4);
	}
	else if( npc->get_name() == "������ʯ" && who->get_legend(TASK_05,10) && !who->get_legend(TASK_05,11) )
	{
		item = new("item/98/0017");
		p = item->move(who,-1);
		if ( !p )
		{
			destruct(item);
			send_user(who,"%c%s",'!', "��Я���Ķ���̫����!");
			return;	
		}
		item->add_to_user(p);
		who->set_legend(TASK_05,11);
		send_user(who,"%c%s",'!', "��õ�"HIY"��������");
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,11,"����֮·(���)" );
		USER_TASK_D->send_task_intro(who,2,TID_WEIGUO,11);
	}
}

void effect_break(object who)
{
	set_effect(who, EFFECT_MINE, 0);
	send_user(who, "%c%c%c", 0x5a, 1, 0);
}