
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <ansi.h>
#include <task.h>

inherit BADMAN;

// ������Զ�̹����Ĺ�
// int is_caster() { return 1; }

// �������Ƿ������ƶ�
// int is_moveable() { return 0; }    // ��ֹʹ�� go ����

// �������������(����֮�е���)
// void follow_user() { }    // ��ֹ�������

// ��������ȡ��������
int get_char_picid() { return 1000; }

// ���������촦��
void create()
{
        set_name("�ٷ�");

        set_char_type(FIGHTER_TYPE);    // init_level Ҫ�õ�
        
        set_head_color(0x0);

        NPC_ENERGY_D->init_level( this_object(), 72+ random(3) );    // 
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
	int p,i,iRate;
	object item;
	i = random(100);
	iRate = i;
	if( who->get_legend(TASK_22, 21) && !who->get_legend(TASK_22, 22) && i < 20 && who->get_save_2("hgnzgcong") < 3 )
	{
		if ( objectp( item = present("��", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{

			if ( item->get_amount() < 3 )
				item->add_amount(1);
		}
		else
		{

			item = new("item/98/0104");
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
		i = who->add_save_2("hgnzgcong",1);
		send_user(who,"%c%s",'!',sprintf(HIY"�� %d/3",i));	
		USER_TASK_D->send_task_intro(who,2,TID_HANGUO,41);
	}
	else if( who->get_legend(TASK_22, 21) && !who->get_legend(TASK_22, 22) && i < 38 && who->get_save_2("hgnzgjiang") < 1 )
	{
		item = new("item/98/0106");
		if ( !item  )
			return ;
		p = item->move(who,-1);
		if ( !p )
		{
			destruct(item);
			return;
		}
		item->add_to_user(p);
		i = who->set_save_2("hgnzgjiang",1);
		send_user(who,"%c%s",'!',sprintf(HIY"�� %d/1",i));	
		USER_TASK_D->send_task_intro(who,2,TID_HANGUO,41);
	}	
	else if( who->get_legend(TASK_22, 21) && !who->get_legend(TASK_22, 22) && i < 56 && who->get_save_2("hgnzgdasuan") < 1)
	{
		item = new("item/98/0105");
		if ( !item  )
			return ;
		p = item->move(who,-1);
		if ( !p )
		{
			destruct(item);
			return;
		}
		item->add_to_user(p);
		i = who->set_save_2("hgnzgdasuan",1);
		send_user(who,"%c%s",'!',sprintf(HIY"���� %d/1",i));	
		USER_TASK_D->send_task_intro(who,2,TID_HANGUO,41);
	}
	if ( who->get_save_2("hgnzgcong") >= 3 && who->get_save_2("hgnzgjiang") >= 1 && who->get_save_2("hgnzgdasuan") >= 1 )
	{
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,41,"���������(���)" );
		who->set_legend(TASK_22, 22);
	}
	if( who->get_legend(TASK_22, 24) && !who->get_legend(TASK_22, 25) && random(100) < 18 )
	{
		item = new("item/98/0107");
		if ( !item  )
			return ;
		p = item->move(who,-1);
		if ( !p )
		{
			destruct(item);
			return;
		}
		item->add_to_user(p);
		who->set_legend(TASK_22, 25);
		send_user(who,"%c%s",'!',sprintf(HIY"�ƽ� %d/1",1));	
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,42,"�𹳹��(���)" );
		USER_TASK_D->send_task_intro(who,2,TID_HANGUO,42);
	}		
	i = random(100);
	if( who->get_legend(TASK_24, 1) && !who->get_legend(TASK_24, 2) && i < 23 && who->get_save_2("xercuanxinlian") < 5 )
	{
		if ( objectp( item = present("������", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{

			if ( item->get_amount() < 5 )
				item->add_amount(1);
		}
		else
		{

			item = new("item/98/0110");
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
		i = who->add_save_2("xercuanxinlian",1);
		send_user(who,"%c%s",'!',sprintf(HIY"������ %d/5",i));	
		USER_TASK_D->send_task_intro(who,2,TID_WEIGUO,29);
	}
	else if( who->get_legend(TASK_24, 1) && !who->get_legend(TASK_24, 2) && i < 46 && who->get_save_2("xerdongcongcao") < 5 )
	{
		if ( objectp( item = present("�����", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{

			if ( item->get_amount() < 5 )
				item->add_amount(1);
		}
		else
		{

			item = new("item/98/0111");
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
		i = who->add_save_2("xerdongcongcao",1);
		send_user(who,"%c%s",'!',sprintf(HIY"����� %d/5",i));	
		USER_TASK_D->send_task_intro(who,2,TID_WEIGUO,29);
	}	
	else if( who->get_legend(TASK_24, 1) && !who->get_legend(TASK_24, 2) && i < 71 && who->get_save_2("xerjinyinhua") < 8)
	{
		if ( objectp( item = present("������", who, 1, MAX_CARRY) ) && item->is_legend_item() == 1 ) 
		{

			if ( item->get_amount() < 8 )
				item->add_amount(1);
		}
		else
		{

			item = new("item/98/0112");
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
		i = who->add_save_2("xerjinyinhua",1);
		send_user(who,"%c%s",'!',sprintf(HIY"������ %d/8",i));	
		USER_TASK_D->send_task_intro(who,2,TID_WEIGUO,29);
	}	
	if ( who->get_save_2("xercuanxinlian") >= 5 && who->get_save_2("xerdongcongcao") >= 5 && who->get_save_2("xerjinyinhua") >= 8 )
	{
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,29,"��ʿ�İ��飨4��(���)" );
		who->set_legend(TASK_24, 2);
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

                if( p < 7446 * rate / 100 ) ;    // NONE

                else if( p < 9246 * rate / 100 )    // ��Ǯ
                {
                        if( gold >= total ) continue;

                        if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item = new( "/item/std/0001" );
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->set_value( 600 + random(260) );
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                gold ++;
                        }
                }         
/*              else if( p < 9246 * rate / 100 )    // ����(����)
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
/*              else if( p < 9246 * rate / 100 )    // ����(����)
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
                else if( p < 9289 * rate / 100 )    // ����(����)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = WEAPON_FILE->get_weapon_file_2(50);  break;
                       case 1 : file = WEAPON_FILE->get_weapon_file_2(60);  break;
                       case 2 : file = WEAPON_FILE->get_weapon_file_2(70);  break;

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
                else if( p < 9350 * rate / 100 )    // ����(����)
                {
                        if( equip >= total2 ) continue;

                        switch( random(3) )
                        {
                       case 0 : file = ARMOR_FILE->get_armor_file_2(50);  break;
                       case 1 : file = ARMOR_FILE->get_armor_file_2(60);  break;
                       case 2 : file = ARMOR_FILE->get_armor_file_2(70);  break;

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
/*              else if( p < 9350 * rate / 100 )    // ���
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
                else if( p < 9850 * rate / 100 )    // ���
                {
                        switch( random(4) )
                        {
                       case 0 : file = "/item/stuff/0192";  break;
                       case 1 : file = "/item/stuff/0148";  break;
                       case 2 : file = "/item/stuff/0051";  break;
                       case 3 : file = "/item/stuff/0049";  break;

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
/*              else if( p < 700000 * rate / 100 )    // ���
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
