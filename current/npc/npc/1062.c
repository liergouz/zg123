
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>
inherit BADMAN;

// ������Զ�̹����Ĺ�
 int is_caster() { return 1; }

// �������Ƿ������ƶ�
// int is_moveable() { return 0; }    // ��ֹʹ�� go ����

// �������������(����֮�е���)
// void follow_user() { }    // ��ֹ�������

// ��������ȡ��������
int get_char_picid() { return 4133; }

// ���������촦��
void create()
{
        set_name("������");

        set_char_type(FIGHTER_TYPE);    // init_level Ҫ�õ�
        
        set_head_color(0x0);

        NPC_ENERGY_D->init_level( this_object(), 106+ random(4) );    // 
        set_max_seek(4);

        setup();

        set_char_type(FIGHTER_TYPE);    // ��������
}

// ��������ȡװ������
int get_weapon_code() { return UNARMED; }

// �������ؼ���������
int perform_action( object who ) { return PF_FILE_04232->perform_action_npc( this_object(), who ); }

// �������Զ�ս��(�����ʱ����)
// void auto_fight( object who ) { }

// ������������(������ʱ����)
void check_legend_task( object who )
{
	int p,i,iRate;
	object item;

	if( who->get_legend(TASK_37, 1) && !who->get_legend(TASK_37, 2) && who->get_save("cysouzsj") < 4 )
	{
		if ( (i=who->add_save("cysouzsj",1)) >= 4 && who->get_save("cysouztb") >= 3 && who->get_save("cytiangmzs") >= 4 )
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,59,"����������(���)" );
			who->set_legend(TASK_37, 2);
		}
		USER_TASK_D->send_task_intro(who,2,TID_QIGUO,59);
		send_user(who,"%c%s",'!',sprintf(HIY"������ %d/4",i));		
	}
	if( who->get_legend(TASK_39, 11) && !who->get_legend(TASK_39, 12) && who->get_save("qgswsouzsj") < 7 )
	{
		if ( (i=who->add_save("qgswsouzsj",1)) >= 7 && who->get_save("qgswsouztb") >= 7 && who->get_save("qgswtiangmzs") >= 5 )
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,55,"��������(���)" );
			who->set_legend(TASK_39, 12);
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,55);
		send_user(who,"%c%s",'!',sprintf(HIY"������ %d/7",i));		
	}
	if( who->get_legend(TASK_39, 14) && !who->get_legend(TASK_39, 15) && random(100) < 18)
	{
		item = new("item/98/0186");
		if ( !item  )
			return ;
		p = item->move(who,-1);
		if ( !p )
		{
			destruct(item);
			return;
		}
		item->add_to_user(p);
		who->set_legend(TASK_39, 15);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,56,"�����ʵף�1��(���)" );
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,56);
		send_user(who,"%c%s",'!',HIY"��ħ֮�� 1/1");		
	}
	if( who->get_legend(TASK_39, 17) && !who->get_legend(TASK_39, 18) )
	{
		if ( who->get_save("qgswmianxian") < 5 && random(100) < 30 )
		{
			if ( objectp( item = present("����", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
			{
	
				if ( item->get_amount() < 5 )
					item->add_amount(1);
			}
			else
			{
	
				item = new("item/98/0187");
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
			i=who->add_save("qgswmianxian",1);
			send_user(who,"%c%s",'!',sprintf(HIY"���� %d/5",i));		
			USER_TASK_D->send_task_intro(who,2,TID_QINGUO,57);
		}
		if ( who->get_save("qgswzaojiao") < 7 && random(100) < 33 )
		{
			if ( objectp( item = present("���", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
			{
	
				if ( item->get_amount() < 7 )
					item->add_amount(1);
			}
			else
			{
	
				item = new("item/98/0188");
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
			i=who->add_save("qgswzaojiao",1);
			send_user(who,"%c%s",'!',sprintf(HIY"��� %d/7",i));		
			USER_TASK_D->send_task_intro(who,2,TID_QINGUO,57);
		}	
		if ( who->get_save("qgswzaojiao")>=7 && who->get_save("qgswmianxian")>=5 )
		{
			who->set_legend(TASK_39, 18);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,57,"�����ʵף�2��(���)" );
		}
	}

	if( who->get_legend(TASK_41, 20) && !who->get_legend(TASK_41, 21) && who->get_save("zzgshouzsj") < 30 )
	{
		if ( (i=who->add_save("zzgshouzsj",1)) >= 30 && who->get_save("zzgshouztb") >= 30 )
		{
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,70,"��̽ʵ��(���)" );
			who->set_legend(TASK_41, 21);
		}
		USER_TASK_D->send_task_intro(who,2,TID_ZHAOGUO,70);
		send_user(who,"%c%s",'!',sprintf(HIY"������ %d/30",i));		
	}
	if( who->get_legend(TASK_43, 17) && !who->get_legend(TASK_43, 18) && random(100) < 23)
	{
		if ( objectp( item = present("�ȼ���", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 5 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0212");
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
		if ( (i=who->add_save("qgswjiujd",1)) >= 5 )
		{
			who->set_legend(TASK_43, 18);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,59,"���ѵİ���(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QINGUO,59);
		send_user(who,"%c%s",'!',sprintf(HIY"�ȼ��� %d/5",i));		
	}
	if( who->get_legend(TASK_44, 4) && !who->get_legend(TASK_44, 5) && random(100) < 38)
	{
		if ( objectp( item = present("������ľͷ", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 30 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0217");
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
		if ( (i=who->add_save("wggjmutou",1)) >= 30 )
		{
			who->set_legend(TASK_44, 5);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,62,"Ư���Ĵ���1��(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_WEIGUO,62);
		send_user(who,"%c%s",'!',sprintf(HIY"������ľͷ %d/30",i));		
	}
	if( who->get_legend(TASK_45, 10) && !who->get_legend(TASK_45, 11) && random(100) < 32)
	{
		if ( objectp( item = present("����", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{
			if ( item->get_amount() < 20 )
				item->add_amount(1);
		}
		else
		{
			item = new("item/98/0223");
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
		if ( (i=who->add_save("qwwenzhu",1)) >= 20 )
		{
			who->set_legend(TASK_45, 11);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,70,"���ϵ���ҫ��2��(���)" );
		}
		USER_TASK_D->send_task_intro(who,2,TID_QIGUO,70);
		send_user(who,"%c%s",'!',sprintf(HIY"���� %d/20",i));		
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

                if( p < 7018 * rate / 100 ) ;    // NONE

                else if( p < 7268 * rate / 100 )    // ��Ǯ
                {
                        if( gold >= total ) continue;

                        if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item = new( "/item/std/0001" );
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->set_value( 810 + random(240) );
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                gold ++;
                        }
                }         
/*              else if( p < 7268 * rate / 100 )    // ����(����)
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
/*              else if( p < 7268 * rate / 100 )    // ����(����)
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
                else if( p < 7280 * rate / 100 )    // ����(����)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = WEAPON_FILE->get_weapon_file_2(80);  break;
                       case 1 : file = WEAPON_FILE->get_weapon_file_2(90);  break;
                       case 2 : file = WEAPON_FILE->get_weapon_file_2(100);  break;

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
                else if( p < 7292 * rate / 100 )    // ����(����)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = ARMOR_FILE->get_armor_file_2(80);  break;
                       case 1 : file = ARMOR_FILE->get_armor_file_2(90);  break;
                       case 2 : file = ARMOR_FILE->get_armor_file_2(100);  break;

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
                       case 0 : file = "/item/40/4079";  break;

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
                       case 0 : file = "/item/91/9120";  break;
                       case 1 : file = "/item/stuff/0130";  break;
                       case 2 : file = "/item/91/9145";  break;
                       case 3 : file = "/item/stuff/0053";  break;

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
/*              else if( p < 1060000 * rate / 100 )    // ���
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
