
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;

// ������Զ�̹����Ĺ�
// int is_caster() { return 1; }

// �������Ƿ������ƶ�
// int is_moveable() { return 0; }    // ��ֹʹ�� go ����

// �������������(����֮�е���)
// void follow_user() { }    // ��ֹ�������

// ��������ȡ��������
int get_char_picid() { return 0651; }

// ���������촦��
void create()
{
        set_name("�ع�ǹ��");

        set_char_type(FIGHTER_TYPE);    // init_level Ҫ�õ�
        
        set_head_color(0x0);

        NPC_ENERGY_D->init_level( this_object(), 66+ random(3) );    // 
        set_max_seek(4);

        setup();

        set_char_type(FIGHTER_TYPE);    // ��������
}

// ��������ȡװ������
int get_weapon_code() { return UNARMED; }

// �������ؼ���������
int perform_action( object who ) { return 0; }    // XXXXX->perform_action_npc( this_object(), who ); }

// �������Զ�ս��(�����ʱ����)
// void auto_fight( object who ) { }

// ������������(������ʱ����)
void check_legend_task( object who )
{
	int p,i;
	object item;
	if( who->get_legend(TASK_18, 16) && !who->get_legend(TASK_18, 17) && random(100) < 35)
	{
		if ( objectp( item = present("��", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 20 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0080");
			if ( !item  )
				return ;
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
				return;
			}
			item->add_to_user(p);
		}
		if ( (i=who->add_save_2("qgdjjjian",1)) >= 20 )
		{
			who->set_save_2("qgdjjjian",20);
			who->set_legend(TASK_18, 17);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,11,"��չ������1��(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,11);
		send_user(who,"%c%s",'!',sprintf(HIY"�� %d/20",i));		
	}
	if( who->get_legend(TASK_18, 22) && !who->get_legend(TASK_18, 23) && random(100) < 35)
	{
		if ( objectp( item = present("��ͷ", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 20 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0081");
			if ( !item  )
				return ;
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
				return;
			}
			item->add_to_user(p);
		}
		if ( (i=who->add_save_2("qgdjjchutou",1)) >= 20 )
		{
			who->set_save_2("qgdjjchutou",20);
			who->set_legend(TASK_18, 23);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,14,"��չ������4��(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,14);
		send_user(who,"%c%s",'!',sprintf(HIY"��ͷ %d/20",i));		
	}
	if( who->get_legend(TASK_18, 25) && !who->get_legend(TASK_18, 26) )
	{
		if ( (i=who->add_save_2("qgdjjqiangbin",1)) >= 20 )
		{
			who->set_save_2("qgdjjqiangbin",20);
			who->set_legend(TASK_18, 26);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,15,"��չ������5��(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,15);
		send_user(who,"%c%s",'!',sprintf(HIY"�ع�ǹ�� %d/20",i));		
	}
	if( who->get_legend(TASK_19, 13) && !who->get_legend(TASK_19, 14) && who->get_save_2("qgswqiangbing",1) < 10)
	{
		if ( (i=who->add_save_2("qgswqiangbing",1)) >= 10 && who->get_save_2("qgswdaodunbing",1) >= 10 )
		{
			who->set_legend(TASK_19, 14);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,20,"�޳ܵ���ͽ(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,20);
		send_user(who,"%c%s",'!',sprintf(HIY"�ع�ǹ�� %d/10",i));		
	}
	if( who->get_legend(TASK_20, 10) && !who->get_legend(TASK_20, 11) && random(100) < 10)
	{
		if ( objectp( item = present("ֽǮ", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 5 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0091");
			if ( !item  )
				return ;
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
				return;
			}
			item->add_to_user(p);
		}
		if ( (i=who->add_save_2("qgbxzhiqian",1)) >= 5 )
		{
			who->set_save_2("qgbxzhiqian",5);
			who->set_legend(TASK_20, 11);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,50,"�����ڣ�1��(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,50);
		send_user(who,"%c%s",'!',sprintf(HIY"ֽǮ %d/5",i));		
	}
	if( who->get_legend(TASK_22, 13) && !who->get_legend(TASK_22, 14) && who->get_save_2("qzgqiangbing",1) < 10)
	{
		if ( (i=who->add_save_2("qzgqiangbing",1)) >= 10 && who->get_save_2("qzgdaodunbing",1) >= 10 && who->get_save_2("qzggongbing",1) >= 10 )
		{
			who->set_legend(TASK_22, 14);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,45,"ǣ��֮��(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,45);
		send_user(who,"%c%s",'!',sprintf(HIY"�ع�ǹ�� %d/10",i));		
	}
}
// ��������������
void drop_items( object who ) { __FILE__ ->drop_items_callout( this_object(), who ); }

// ��������������(���߸���)
void drop_items_callout( object me, object who )
{
        object item, leader;
        string file, owner, id;
        int p, rate, i, size, gold, equip, total, total2 ;
        int z, x, y;

        z = get_z(me);  x = get_x(me);  y = get_y(me);
        id = who->get_leader();
        if (!id) owner = who->get_id();
        else
        {
        	if ( leader = find_player(id ) )
        	{
        		owner = leader->get_id();
		}      
		else
			owner = who->get_id();  		
	}

        p = random(100);  size = ( p > 2 ) ? 1 : ( p > 0 ) ? 2 : 8;  total = 2;  total2 = 3;
//      p = random(100);  size = ( p > 40 ) ? 3 : 10;  total = 2;  total2 = 3;

        rate = me->correct_drop_rate( me->get_level() - who->get_level() ) * who->get_online_rate() / 100;

        for( i = 0; i < size; i ++ )
        {
                p = random(10000);

                if( p < 5521 * rate / 100 ) ;    // NONE

                else if( p < 5771 * rate / 100 )    // ��Ǯ
                {
                        if( gold >= total ) continue;

                        if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item = new( "/item/std/0001" );
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->set_value( 460 + random(60) );
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                gold ++;
                        }
                }         
/*              else if( p < 5771 * rate / 100 )    // ����(����)
                {
                        if( equip >= total2 ) continue;

                        file = WEAPON_FILE->get_weapon_file_0(0);
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                ITEM_EQUIP_D->init_equip_prop(item);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                equip ++;
                        }
                }       */
/*              else if( p < 5771 * rate / 100 )    // ����(����)
                {
                        if( equip >= total2 ) continue;

                        file = ARMOR_FILE->get_armor_file_0(0);
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                ITEM_EQUIP_D->init_equip_prop(item);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                equip ++;
                        }
                }       */
                else if( p < 5832 * rate / 100 )    // ����(����)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = WEAPON_FILE->get_weapon_file_2(40);  break;
                       case 1 : file = WEAPON_FILE->get_weapon_file_2(50);  break;
                       case 2 : file = WEAPON_FILE->get_weapon_file_2(60);  break;

                      default : break;
                        }
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                ITEM_EQUIP_D->init_equip_prop(item);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                equip ++;
                        }
                }         
                else if( p < 5884 * rate / 100 )    // ����(����)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = ARMOR_FILE->get_armor_file_2(40);  break;
                       case 1 : file = ARMOR_FILE->get_armor_file_2(50);  break;
                       case 2 : file = ARMOR_FILE->get_armor_file_2(60);  break;

                      default : break;
                        }
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                ITEM_EQUIP_D->init_equip_prop(item);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                equip ++;
                        }
                }         
                else if( p < 9350 * rate / 100 )    // ���
                {
                        switch( random(1) )
                        {
                       case 0 : file = "/item/40/4056";  break;

                      default : break;
                        }
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                        }
                }         
                else if( p < 9850 * rate / 100 )    // ���
                {
                        switch( random(4) )
                        {
                       case 0 : file = "/item/stuff/0171";  break;
                       case 1 : file = "/item/stuff/0192";  break;
                       case 2 : file = "/item/stuff/0148";  break;
                       case 3 : file = "/item/stuff/0051";  break;

                      default : break;
                        }
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                        }
                }         
                else if( p < 9950 * rate / 100 )    // ���
                {
                        switch( random(2) )
                        {
                       case 0 : file = "/item/41/4110";  break;
                       case 1 : file = "/item/stuff/0310";  break;

                      default : break;
                        }
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                        }
                }         
                else if( p < 10000 * rate / 100 )    // ���
                {
                        switch( random(1) )
                        {
                       case 0 : file = "/item/stuff/0309";  break;

                      default : break;
                        }
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                        }
                }         
/*              else if( p < 680000 * rate / 100 )    // ���
                {
                        switch( random(0) )
                        {

                      default : break;
                        }
                        if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                        {
                                item = new(file);
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                        }
                }       */

        }       
}
