
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <music.h>
#include <skill.h>

inherit NPC;
int hptime,sumtime;
void summon_guard();

// �������Ƿ��ܽ���
int cannot_enter_city() { return 1; }

// ���������촦��
void create()
{
        set_name("�ٷ�");
        set_char_picid(0252);    // ǿ��
        set_char_type(FIGHTER_TYPE);
        set_walk_speed(WALK_SPEED_4);
        set_attack_speed(20);
        set_level(95);

        setup();

        set( "birthday", time() );
}

// ��������ȡװ������
int get_weapon_code() { return UNARMED; }

// ��������λ����
void reset() 
{
	int i;
	object npc,me=this_object();
        if( gone_time( get("birthday") ) >= 1200 )    // 20 ����
        {
		for(i=0;i<4;i++)
		{
			if ( objectp(npc=me->get(sprintf("guard%d",i))) )
			{
				npc->remove_from_scene();
				destruct(npc);
			}
		}
                remove_from_scene(3321);
                destruct( this_object() );
        }
}

// --------------------------------------------------------------- Զ�̵��� ----

// ��������������
void win_bonus( object who ) { __FILE__ ->win_bonus_callout( this_object(), who ); }

// ��������������(���߸���)
void win_bonus_callout( object me, object who )
{
        object owner, *team,npc;
        int level, level2, exp, exp2, pot, pot2;
        int id, i, size;

	for(i=0;i<2;i++)
	{
		if ( objectp(npc=me->get(sprintf("guard%d",i))) )
		{
			npc->remove_from_scene();
			destruct(npc);
		}
	}
        if( !me->can_be_fighted(who) ) return;

        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return;

        __FILE__ ->drop_items(me, who);

        // ---------- ���һ��������װ�� ///// �������������侭�� ----------

        if( !objectp( who = me->get_enemy_4() ) ) return;

        if( !me->can_be_fighted(who) ) return;

        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return;

        level = me->get_level();

        exp = NPC_ENERGY_D->get_exp_bonus(level)*19+random(501);
        pot = level * 4 + random(11);

        if( who->get_leader() && arrayp( team = who->get_team() ) && sizeof(team) > 1 )
        {
                team = me->correct_bonus_team1(team,20);
                size = sizeof(team);
        }
        else    size = 1;

        if( size > 1 )    // ����
        {
                for( i = 0; i < size; i ++ ) if( team[i] )
                {
                        level2 = level - team[i]->get_level();
                        exp2 = me->correct_exp_bonus(level, level2, exp);  team[i]->add_exp(exp2);    // add_exp(exp2, 1);
                        pot2 = me->correct_exp_bonus(level, level2, pot);  team[i]->add_potential(pot2);

                        team[i]->add_log("&monster", exp2);
                        team[i]->add_log("*monster", pot2);
                        team[i]->add_log("#monster", 1);

                        send_user( team[i], "%c%w", 0x0d, MUSIC_TASK );
                        write_user( team[i], ECHO "�����������%s������ %+d, Ǳ�� %+d��", me->get_name(), exp2, pot2 );
                }
        }
        else    // ����
        {
                level2 = level - who->get_level();
                exp2 = me->correct_exp_bonus(level, level2, exp);  who->add_exp(exp2);    // add_exp(exp2, 1);
                pot2 = me->correct_exp_bonus(level, level2, pot);  who->add_potential(pot2);

                who->add_log("&monster", exp2);
                who->add_log("*monster", pot2);
                who->add_log("#monster", 1);

                send_user( who, "%c%w", 0x0d, MUSIC_TASK );
                write_user( who, ECHO "��������%s������ %+d, Ǳ�� %+d��", me->get_name(), exp2, pot2 );
        }

        if(     ( id = me->get("task") )
        &&      ( owner = find_player( sprintf("%d", id) ) ) )
        {
                exp2 = exp / 10 + 1 ;
                pot2 = pot / 10 + 1 ;                
                owner->add_exp(exp2);
                owner->add_potential(pot2);
                owner->add_log("&monster2", exp2);
                owner->add_log("*monster2", pot2);
                owner->add_log("#monster2", 1);

                send_user( owner, "%c%w", 0x0d, MUSIC_TASK );
                write_user( owner, ECHO "ϴ������%s�������ˣ����� %+d, Ǳ�� %+d��", me->get_name(), exp2, pot2 );
        }
}

// ��������������
void drop_items( object me, object who )
{
        object item;
        string file;
        int p, rate, level, level2;
        int z, x, y;

        z = get_z(me);  x = get_x(me);  y = get_y(me);

        p = random(10000);  level = me->get_level();

        rate = me->correct_drop_rate( level - who->get_level() );

        if( p < 3070 * rate / 100 ) ;    // NONE

        else if( p < 7120 * rate / 100 )    // ��Ǯ
        {
                if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                {
                        item = new( "/item/std/0001" );
                        TEAM_D->drop_item(item,who);
                        item->set_user_id(who->get_id());
                        item->set_value( level * 100 + random(1001) );
                        item->add_to_scene(z, p / 1000, p % 1000);
                        item->set("winner", who);
                        item->set( "time", time() );
                }
        }
        else if( p < 9570 * rate / 100 )    // ����ҩ��
        {
                switch( random(2) )
                {
               case 0 : file = "/item/91/9102";  break;
               case 1 : file = "/item/91/9112";  break;
                }
                if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                {
                        item = new( file );
                        TEAM_D->drop_item(item,who);
                        item->set_user_id(who->get_id());
                        item->add_to_scene(z, p / 1000, p % 1000);
                        item->set("winner", who);
                        item->set( "time", time() );
                }
        }
        else if( p < 9870 * rate / 100 )    // ������װ��
        {
                level2 = range_value(level - 5*random(3), 0, level);
                if( random(2) ) 
                        file = ARMOR_FILE->get_armor_file_2(level2);
                else    file = WEAPON_FILE->get_weapon_file_2(level2);
                if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                {
                        item = new( file );
                        TEAM_D->drop_item(item,who);
                        item->set_user_id(who->get_id());
                        ITEM_EQUIP_D->init_equip_prop(item);
                        item->add_to_scene(z, p / 1000, p % 1000);
                        item->set("winner", who);
                        item->set( "time", time() );
                }
        }
        else if( p < 9880 * rate / 100 )    // һ����ʯ
        {
                file = STONE_FILE->get_diamond_file();
                if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                {
                        item = new(file);
                        TEAM_D->drop_item(item,who);
                        item->set_user_id(who->get_id());
                        item->set_level(1);
                        item->add_to_scene(z, p / 1000, p % 1000);
                        item->set("winner", who);
                        item->set( "time", time() );
                }
        }
        else if( p < 9940 * rate / 100 )    // ������ϵĵͼ��м��Ʒ
        {
                file = "sys/item/product"->get_random_mid_product();
                if( load_object(file) && ( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) ) )
                {
                        item = new(file);
                        TEAM_D->drop_item(item,who);
                        item->set_user_id(who->get_id());
                        item->add_to_scene(z, p / 1000, p % 1000);
                        item->set("winner", who);
                        item->set( "time", time() );
                }
        }


}

void heart_beat_walk()
{
	int x,y,z,x0,y0,z0,i,x1,y1,p;
	object enemy,me;
	
	enemy = get_enemy();
	me = this_object();
	if ( enemy && (!sumtime || gone_time(sumtime) > 60 ))
	{
		sumtime = time();
		summon_guard();		
	}
	if ( gone_time(hptime) >= 20+random(21) )
	{
		hptime = time();
		//˲���ƶ�
		if ( objectp(enemy) )
		{
			z = get_z(enemy);z0=get_z(me);
			
			if( z == z0 && distance_between(me, enemy) < 20 )
			{
				x = get_x(enemy);y = get_y(enemy);
				x0 = get_x(me);y0 = get_y(me);
			        for( i = 0; i < 10; i ++ )
			        {
			                if( p = get_valid_xy(z, abs( x + random(3) - 1 ), abs( y + random(3) - 1 ), IS_CHAR_BLOCK) )
			                {
			                        x1 = p / 1000;  y1 = p % 1000;  break;
			                }
			        }
			        if ( x1 && y1 && z && !MAP_D->is_inside_city(z, x1, y1) )
			        {
		                        send_user( get_scene_object_2(me, USER_TYPE), "%c%w%w%w%c%c%c", 0x4f, x0, y0, 9413, 1, OVER_BODY, PF_ONCE );    // ����ָ��
		                        me->add_to_scene( z, x1, y1 );
		                        me->to_front_xy(x, y);
				}
			}
			
		}
	}

	::heart_beat_walk();	
}

void summon_guard()
{
	int i,x,y,z,p,level;
	object npc,me=this_object();
	
	x = get_x(me);y = get_y(me);z = get_z(me);
	level = me->get_level();
	for(i=0;i<2;i++)
	{
		if ( objectp(npc=get(sprintf("guard%d",i))) )
		{
			npc->remove_from_scene();
			destruct(npc);
		}
		p = get_valid_xy(z, x + random(10) - 5, y + random(10) - 5, IS_CHAR_BLOCK);
		if ( !p )
			continue;
		npc = new("npc/task/8006");	
		if ( !npc )
			break;
		set(sprintf("guard%d",i),npc);
		NPC_ENERGY_D->init_level(npc, level);
		npc->set_ap(npc->get_ap()*7/10);
		npc->add_to_scene( z, p / 1000, p % 1000);
		npc->set_owner(me);
		NPC_SLAVE_D->find_enemy(npc);    // Ѱ�ҵ���
		send_user( get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(npc), 
                        41311, 1, OVER_BODY, 41312, 1, OVER_BODY, 41313, 1, UNDER_FOOT, PF_ONCE );
	}
	
}