
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
int get_char_picid() { return 0802; }

// ���������촦��
void create()
{
        set_name("˫������");

        set_char_type(FIGHTER_TYPE);    // init_level Ҫ�õ�
        
        set_head_color(0x0);

        NPC_ENERGY_D->init_level( this_object(), 80+ random(4) );    // 
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

	if ( who->get_legend(TASK_27,16) && !who->get_legend(TASK_27,17) && random(100) < 15 )
	{
		item = new("item/98/0131");
		p = item->move(who,-1);
		if ( p )
		{
			item->add_to_user(p);
			who->set_legend(TASK_27,17);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,43,"���������棨4��(���)" );	
			USER_TASK_D->send_task_intro(who,2,TID_ZHAOGUO,43);
			send_user(who,"%c%s",'!',"ͬ���� 1/1");		
		}
		else
		{
			destruct(item);	
		}
	}
	if( who->get_legend(TASK_27, 28) && !who->get_legend(TASK_27, 29) && random(100) < 38 )
	{
		if ( objectp( item = present("¹��", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 20 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0132");
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
		if ( (i=who->add_save("zgswlujiao",1)) >= 20 )
		{
			who->set_save("zgswlujiao",20);
			who->set_legend(TASK_27, 29);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,44,"¹��(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_ZHAOGUO,44);
		send_user(who,"%c%s",'!',sprintf(HIY"¹�� %d/20",i));		
	}
	if( who->get_legend(TASK_28, 1) && !who->get_legend(TASK_28, 2) && who->get_save("zgswmuban") < 8 && random(100) < 23 )
	{
		if ( objectp( item = present("ľ��", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 8 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0133");
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
		if ( (i=who->add_save("zgswmuban",1)) >= 8 && who->get_save("zgswyushi")>=3)
		{
			who->set_save("zgswmuban",8);
			who->set_legend(TASK_28, 2);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,45,"���(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_ZHAOGUO,45);
		send_user(who,"%c%s",'!',sprintf(HIY"ľ�� %d/8",i));		
	}
	if( who->get_legend(TASK_28, 1) && !who->get_legend(TASK_28, 2) && who->get_save("zgswyushi") < 3 && random(100) < 20 )
	{
		if ( objectp( item = present("��ʯ", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 3 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0134");
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
		if ( (i=who->add_save("zgswyushi",1)) >= 3 && who->get_save("zgswmuban")>=8)
		{
			who->set_save("zgswyushi",3);
			who->set_legend(TASK_28, 2);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,45,"���(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_ZHAOGUO,45);
		send_user(who,"%c%s",'!',sprintf(HIY"��ʯ %d/3",i));		
	}
	if( who->get_legend(TASK_28, 26) && !who->get_legend(TASK_28, 27) && who->get_save("zgdjjsuangdaokl") < 8)
	{
		if ( (i=who->add_save("zgdjjsuangdaokl",1)) >= 8 && who->get_save("zgdjjdaodunkl") >= 10 && who->get_save("zgdjjjiandunkl") >= 10)
		{
			who->set_save("zgdjjsuangdaokl",8);
			who->set_legend(TASK_28, 27);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,52,"֤��ʵ��(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_ZHAOGUO,52);
		send_user(who,"%c%s",'!',sprintf(HIY"˫������ %d/8",i));		
	}
	if( who->get_legend(TASK_29, 4) && !who->get_legend(TASK_29, 5) )
	{
		if ( who->get_save("wgswlingzc") < 1 && random(100) < 15 )
		{

			item = new("item/98/0138");
			if ( !item  )
				return ;
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
				return;
			}
			item->add_to_user(p);
			who->set_save("wgswlingzc",1);
			USER_TASK_D->send_task_intro(who,2,TID_WEIGUO,31);
			send_user(who,"%c%s",'!',sprintf(HIY"��֥�� %d/1",1));			
		}
		else if ( who->get_save("wgswqian") < 1 && random(100) < 15 )
		{

			item = new("item/98/0139");
			if ( !item  )
				return ;
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
				return;
			}
			item->add_to_user(p);
			who->set_save("wgswqian",1);
			USER_TASK_D->send_task_intro(who,2,TID_WEIGUO,31);
			send_user(who,"%c%s",'!',sprintf(HIY"Ǯ %d/1",1));			
		}
		else if ( who->get_save("wgswxiaomi") < 10 && random(100) < 20 )
		{

			if ( objectp( item = present("С��", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
			{
				if ( item->get_amount() < 10 )
					item->add_amount(1);
			}
			else
			{
				item = new("item/98/0140");
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
			i = who->add_save("wgswxiaomi",1);
			USER_TASK_D->send_task_intro(who,2,TID_WEIGUO,31);
			send_user(who,"%c%s",'!',sprintf(HIY"С�� %d/10",i));			
		}
		if ( who->get_save("wgswlingzc") && who->get_save("wgswqian") && who->get_save("wgswxiaomi")>=10 )
		{
			who->set_legend(TASK_29, 5);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,31,"������Σ��(���)" );
		}
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

                if( p < 6076 * rate / 100 ) ;    // NONE

                else if( p < 6326 * rate / 100 )    // ��Ǯ
                {
                        if( gold >= total ) continue;

                        if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item = new( "/item/std/0001" );
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->set_value( 640 + random(250) );
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                gold ++;
                        }
                }         
/*              else if( p < 6326 * rate / 100 )    // ����(����)
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
/*              else if( p < 6326 * rate / 100 )    // ����(����)
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
                else if( p < 6360 * rate / 100 )    // ����(����)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = WEAPON_FILE->get_weapon_file_2(60);  break;
                       case 1 : file = WEAPON_FILE->get_weapon_file_2(70);  break;
                       case 2 : file = WEAPON_FILE->get_weapon_file_2(80);  break;

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
                else if( p < 6380 * rate / 100 )    // ����(����)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = ARMOR_FILE->get_armor_file_2(60);  break;
                       case 1 : file = ARMOR_FILE->get_armor_file_2(70);  break;
                       case 2 : file = ARMOR_FILE->get_armor_file_2(80);  break;

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
                        switch( random(2) )
                        {
                       case 0 : file = "/item/40/4066";  break;
                       case 1 : file = "/item/40/4065";  break;

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
                        switch( random(5) )
                        {
                       case 0 : file = "/item/stuff/0129";  break;
                       case 1 : file = "/item/stuff/0146";  break;
                       case 2 : file = "/item/stuff/0148";  break;
                       case 3 : file = "/item/stuff/0053";  break;
                       case 4 : file = "/item/stuff/0051";  break;

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
/*              else if( p < 840000 * rate / 100 )    // ���
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
