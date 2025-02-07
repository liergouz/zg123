
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;
object boss1;

// ��������ȡ��������
int get_char_picid() { return 0052; }

// ���������촦��
void create()
{
        set_name("���������");

	set_max_hp(450);
	set_ap(38);
	set_dp(25);
	set_pp(15);
	set_sp(38);
	set_walk_speed(6);
	set_attack_speed(30);
        set_max_seek(4);

        setup();
        set_char_type(FIGHTER_TYPE_2);    
}
// ���������Խ���ս��
int can_be_fighted( object who ) 
{ 
	return 1;
	
//        object owner, me;
//        string leader;
//        int id;
//        me = this_object();
//
//        if( owner = who->get_owner() ) who = owner;
//        if( who->is_npc() ) return 0;
//        if( who->get_enemy() == this_object() ) return 1;
//
//	if ( who->get_legend(TASK_NEWBIE_02, 28)&&!who->get_legend(TASK_NEWBIE_02, 29) )
//		return 1;            
//	if ( !objectp(owner) )
//       		send_user( who, "%c%s", '!', get_name() + "����ͬ���ܡ�" );
//        return 0;
}

int can_fight( object who ) 
{ 
	return 1;

//        object owner, me;
//        string leader;
//        int id;
//        me = this_object();
//
//        if( owner = who->get_owner() ) who = owner;
//        if( who->is_npc() ) return 0;
//        if( who->get_enemy() == this_object() ) return 1;
//
//
//	if ( who->get_legend(TASK_NEWBIE_02, 28)&&!who->get_legend(TASK_NEWBIE_02, 29) )
//	{			
//		return 1;            
//	}
//	
//        return 0;
}

//void follow_user() 
//{
//	object who;
//	who = get_enemy();
//	if ( objectp(who) && who->get_legend(TASK_NEWBIE_02, 14)&&!who->get_legend(TASK_NEWBIE_02, 15) )
//		::follow_user();
//}
// --------------------------------------------------------------- Զ�̵��� ----

void create_npc()
{
	remove_call_out("create_npc");
	if ( !objectp(boss1) )
	{
		boss1 = new("npc/task/0101");
		if ( boss1 )
			boss1->add_to_scene(1,244,157,1);
	}
	else if ( get_z(boss1) != 1 || get_x(boss1) != 244 || get_y(boss1) != 157 )
		boss1->add_to_scene( 1, 244, 157, 1, 40971, 0, 40971, 0 );
	call_out("create_npc",180);
}

void check_legend_task( object who )
{
//        if ( who->get_legend(TASK_NEWBIE_02, 28)&&!who->get_legend(TASK_NEWBIE_02, 29) )
//        {
//		who->set_legend(TASK_NEWBIE_02, 29);
//		//send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,22,"����֮ս(�Ѿ����)" );
//		USER_TASK_D->send_task_intro(who,2,TID_NEWBIE_01,22);
//		send_user( who, "%c%s", '!', HIY"����֮ս"NOR" �������");			
//		who->add_exp(80);
//		who->add_potential(1);
//		send_user(who,"%c%s",';',"��õ�80�㾭���1��Ǳ��");
//	}	
}