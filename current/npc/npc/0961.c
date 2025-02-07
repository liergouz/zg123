
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
int get_char_picid() { return 0951; }

// ���������촦��
void create()
{
        set_name("ľ��");

        set_char_type(FIGHTER_TYPE);    // init_level Ҫ�õ�
        
        set_head_color(0x0);

        NPC_ENERGY_D->init_level( this_object(), 96+ random(4) );    // 
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

	if( who->get_legend(TASK_33, 1) && !who->get_legend(TASK_33, 2) && who->get_save("ltmuj") < 7 )
	{
		if ( (i=who->add_save("ltmuj",1)) >= 7 && who->get_save("ltjinj") >= 5)
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,33,"�游���Ų���3��(���)" );
			who->set_legend(TASK_33, 2);
		}
		USER_TASK_D->send_task_intro(who,2,TID_CHUGUO,33);
		send_user(who,"%c%s",'!',sprintf(HIY"ľ�� %d/7",i));		
	}
	if( who->get_legend(TASK_33, 10) && !who->get_legend(TASK_33, 11) && random(100) < 30 )
	{
		if ( objectp( item = present("��������", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 20 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0155");
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
		if ( (i=who->add_save("cgswtiegy",1)) >= 20 )
		{
			who->set_save("cgswtiegy",20);
			who->set_legend(TASK_33, 11);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,36,"��������(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_CHUGUO,36);
		send_user(who,"%c%s",'!',sprintf(HIY"�������� %d/20",i));		
	}
	if( who->get_legend(TASK_33, 13) && !who->get_legend(TASK_33, 14) && random(100) < 30 )
	{
		if ( objectp( item = present("õ�廨", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 11 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0156");
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
		if ( (i=who->add_save("cgswmeigui",1)) >= 11 )
		{
			who->set_save("cgswmeigui",11);
			who->set_legend(TASK_33, 14);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,37,"õ�廨(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_CHUGUO,37);
		send_user(who,"%c%s",'!',sprintf(HIY"õ�廨 %d/11",i));		
	}
	if( who->get_legend(TASK_39, 28) && !who->get_legend(TASK_39, 29) )
	{
		if ( who->get_save("gsbtieku") == 0 && random(100) < 20 )
		{
			item = new("item/98/0191");
			if ( !item  )
				return ;
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
				return;
			}
			item->add_to_user(p);
			who->set_save("gsbtieku",1);
			send_user(who,"%c%s",'!',sprintf(HIY"���� %d/1",1));		
			USER_TASK_D->send_task_intro(who,2,TID_ZHOUGUO,8);
		}
		else if ( who->get_save("gsbmutou") < 5 && random(100) < 23 )
		{
			if ( objectp( item = present("�����ľͷ", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
			{
				if ( item->get_amount() < 5 )
					item->add_amount(1);
			}
			else
			{
				item = new("item/98/0192");
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
			i=who->add_save("gsbmutou",1);
			USER_TASK_D->send_task_intro(who,2,TID_ZHOUGUO,8);
			send_user(who,"%c%s",'!',sprintf(HIY"�����ľͷ %d/5",i));		
		}
		if (  who->get_save("gsbtieku") && who->get_save("gsbmutou") >=5 )
		{
			who->set_legend(TASK_39, 29);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,8,"������裨4��(���)" );
		}
	}
	if( who->get_legend(TASK_45, 26) && !who->get_legend(TASK_45, 27) && random(100) < 18)
	{
		item = new("item/98/0227");
		if ( !item  )
			return ;
		p = item->move(who,-1);
		if ( !p )
		{
			destruct(item);
			return;
		}
		item->add_to_user(p);
		who->set_legend(TASK_45, 27);
		USER_TASK_D->send_task_intro(who,2,TID_YUNMENZE,2);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YUNMENZE,2,"��ҽ��4��(���)" );
		send_user(who,"%c%s",'!',HIY"���� 1/1");		
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

                if( p < 6852 * rate / 100 ) ;    // NONE

/*              else if( p < 6852 * rate / 100 )    // ��Ǯ
                {
                        if( gold >= total ) continue;

                        if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item = new( "/item/std/0001" );
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->set_value( 0 + random(0) );
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                gold ++;
                        }
                }       */
/*              else if( p < 6852 * rate / 100 )    // ����(����)
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
/*              else if( p < 6852 * rate / 100 )    // ����(����)
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
                else if( p < 6866 * rate / 100 )    // ����(����)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = WEAPON_FILE->get_weapon_file_2(70);  break;
                       case 1 : file = WEAPON_FILE->get_weapon_file_2(80);  break;
                       case 2 : file = WEAPON_FILE->get_weapon_file_2(90);  break;

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
                else if( p < 6880 * rate / 100 )    // ����(����)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = ARMOR_FILE->get_armor_file_2(70);  break;
                       case 1 : file = ARMOR_FILE->get_armor_file_2(80);  break;
                       case 2 : file = ARMOR_FILE->get_armor_file_2(90);  break;

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
                       case 0 : file = "/item/40/4074";  break;

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
                       case 1 : file = "/item/stuff/0027";  break;
                       case 2 : file = "/item/stuff/0053";  break;
                       case 3 : file = "/item/stuff/0187";  break;

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
/*              else if( p < 980000 * rate / 100 )    // ���
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
