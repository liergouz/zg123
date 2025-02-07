
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;

// ������Զ�̹����Ĺ�
 int is_caster() { return 0; }

// �������Ƿ������ƶ�
// int is_moveable() { return 0; }    // ��ֹʹ�� go ����

// �������������(����֮�е���)
// void follow_user() { }    // ��ֹ�������

// ��������ȡ��������
int get_char_picid() { return 1102; }

// ���������촦��
void create()
{
        set_name("ǹ��");

        set_char_type(FIGHTER_TYPE);    // init_level Ҫ�õ�
        
        set_head_color(0x0);

        NPC_ENERGY_D->init_level( this_object(), 110+ random(4) );    // 
        set_max_seek(4);

        setup();

        set_char_type(FIGHTER_TYPE);    // ��������
}

// ��������ȡװ������
int get_weapon_code() { return UNARMED; }

// �������ؼ���������
int perform_action( object who ) { return 0; }

// �������Զ�ս��(�����ʱ����)
// void auto_fight( object who ) { }

// ������������(������ʱ����)
void check_legend_task( object who ) 
{
	int p,i,iRate;
	object item;
	if( who->get_legend(TASK_44, 10) && !who->get_legend(TASK_44, 11) && random(100) < 23)
	{
		if ( objectp( item = present("Ư���Ļƾ�ʯ", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 8 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0219");
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
		if ( (i=who->add_save("wggjhuangjs",1)) >= 8 )
		{
			who->set_legend(TASK_44, 11);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,64,"Ư���Ĵ���3��(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_WEIGUO,64);
		send_user(who,"%c%s",'!',sprintf(HIY"Ư���Ļƾ�ʯ %d/8",i));		
	}
	if( who->get_legend(TASK_44, 24) && !who->get_legend(TASK_44, 25) )
	{
		if ( (i=who->add_save("lituqianhun",1)) >= 10 )
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,66,"������ů��1��(���)" );
			who->set_legend(TASK_44, 25);
		}
		USER_TASK_D->send_task_intro(who,2,TID_QIGUO,66);
		send_user(who,"%c%s",'!',sprintf(HIY"ǹ�� %d/10",i));		
	}
	if( who->get_legend(TASK_44, 27) && !who->get_legend(TASK_44, 28) && random(100) < 28)
	{
		if ( objectp( item = present("�Ͳ���", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 10 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0221");
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
		if ( (i=who->add_save("lituyoucaizi",1)) >= 10 )
		{
			who->set_legend(TASK_44, 28);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,67,"������ů��2��(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QIGUO,67);
		send_user(who,"%c%s",'!',sprintf(HIY"�Ͳ��� %d/10",i));		
	}
	if( who->get_legend(TASK_45, 4) && !who->get_legend(TASK_45, 5) && random(100) < 20)
	{
		if ( objectp( item = present("�ع�����", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 5 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0222");
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
		if ( (i=who->add_save("qgdjjkuijia",1)) >= 5 )
		{
			who->set_legend(TASK_45, 5);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,63,"�캮�ض�(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,63);
		send_user(who,"%c%s",'!',sprintf(HIY"�ع����� %d/5",i));		
	}	
	if( who->get_legend(TASK_45, 15) && !who->get_legend(TASK_45, 16) )
	{
		if ( (i=who->add_save("cwqianhun",1)) >= 12 )
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,41,"���ھ���(���)" );
			who->set_legend(TASK_45, 16);
		}
		USER_TASK_D->send_task_intro(who,2,TID_CHUGUO,41);
		send_user(who,"%c%s",'!',sprintf(HIY"ǹ�� %d/12",i));		
	}
	if( who->get_legend(TASK_45, 23) && !who->get_legend(TASK_45, 24) && random(100) < 18)
	{
		item = new("item/98/0226");
		if ( !item  )
			return ;
		p = item->move(who,-1);
		if ( !p )
		{
			destruct(item);
			return;
		}
		item->add_to_user(p);
		who->set_legend(TASK_45, 24);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YUNMENZE,1,"��ҽ��3��(���)" );
		USER_TASK_D->send_task_intro(who,2,TID_YUNMENZE,1);
		send_user(who,"%c%s",'!',HIY"��Ƥ 1/1");		
	}
	if( who->get_legend(TASK_46, 8) && !who->get_legend(TASK_46, 9) && who->get_save("mxqianhun") < 30 )
	{
		if ( (i=who->add_save("mxqianhun",1)) >= 30 && who->get_save("mxdaohun") >= 30 )
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,67,"���괫˵4(���)" );
			who->set_legend(TASK_46, 9);
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,67);
		send_user(who,"%c%s",'!',sprintf(HIY"ǹ�� %d/30",i));		
	}		
	if( who->get_legend(TASK_46, 15) && !who->get_legend(TASK_46, 16) && who->get_save("qysqianhun") < 30 )
	{
		if ( (i=who->add_save("qysqianhun",1)) >= 30 && who->get_save("qysjianhun") >= 30 )
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,70,"ƽ��֮��2(���)" );
			who->set_legend(TASK_46, 16);
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,70);
		send_user(who,"%c%s",'!',sprintf(HIY"ǹ�� %d/30",i));		
	}
	if( who->get_legend(TASK_47, 23) && !who->get_legend(TASK_47, 24) && who->get_save("xhdqianhun") < 30 )
	{
		if ( (i=who->add_save("xhdqianhun",1)) >= 30 && who->get_save("xhdjianhun") >= 30 )
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,86,"��ȡ��3(���)" );
			who->set_legend(TASK_47, 24);
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,86);
		send_user(who,"%c%s",'!',sprintf(HIY"ǹ�� %d/30",i));		
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

                if( p < 7412 * rate / 100 ) ;    // NONE

/*              else if( p < 7412 * rate / 100 )    // ��Ǯ
                {
                        if( gold >= total ) continue;

                        if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item = new( "/item/std/0001" );
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->set_value( 800 + random(300) );
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                gold ++;
                        }
                }       */
/*              else if( p < 7412 * rate / 100 )    // ����(����)
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
/*              else if( p < 7412 * rate / 100 )    // ����(����)
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
                else if( p < 7419 * rate / 100 )    // ����(����)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = WEAPON_FILE->get_weapon_file_2(90);  break;
                       case 1 : file = WEAPON_FILE->get_weapon_file_2(100);  break;
                       case 2 : file = WEAPON_FILE->get_weapon_file_2(110);  break;

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
                else if( p < 7426 * rate / 100 )    // ����(����)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = ARMOR_FILE->get_armor_file_2(90);  break;
                       case 1 : file = ARMOR_FILE->get_armor_file_2(100);  break;
                       case 2 : file = ARMOR_FILE->get_armor_file_2(110);  break;

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
                       case 0 : file = "/item/40/4082";  break;

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
                       case 0 : file = "/item/stuff/0130";  break;
                       case 1 : file = "/item/91/9145";  break;
                       case 2 : file = "/item/stuff/0053";  break;
                       case 3 : file = "/item/stuff/0195";  break;

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
                       case 0 : file = "/item/41/4109";  break;
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
/*              else if( p < 1110000 * rate / 100 )    // ���
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
