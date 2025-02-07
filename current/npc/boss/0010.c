#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <cmd.h>
#include <skill.h>

#define _DEBUG(x)	tell_user(find_char("971"),x);

inherit NPC;

int flag;
int saytime,hptime,RelaxTime,pTime,pTime1,iRelax;
string *nFamily = ({"�һ�Դ","��ɽ","������","����","éɽ","����ɽ","������"});
// �������Ƿ��ܽ���
int cannot_enter_city() { return 1; }
int get_id_color() { return 0x800080; }
int is_caster () { return 1; }
void drop_items( object me, object who );

// �������������齱��
int correct_exp_bonus( int level, int level2, int exp ) { return exp; }

// ����������������
int correct_drop_rate( int level ) { return 100; }

// ��������ȡ��������
string get_short() 
{ 
        return this_object()->get_name(); 
}

void init_fight_status()
{
	set_ap(1300);
	set_dp(400);
	set_cp(1300);
	set_pp(500);
	set_sp(300);	
}

// ���������촦��
void create()
{
	object me = this_object();
        set_name("������");
        set_head_color(0x21d0);
        set_char_picid(450); 
        set_level(70);
        set_max_hp(3500000);
        set_max_mp(1000);
	init_fight_status();
        set_walk_speed(2);
        set_attack_speed(20);
        set_max_seek(6);
        set_walk_step(2);
        set("no_sk04211",1);	//����������û��Ч��
        set("anti_sleep",1);	//�������
        set("anti_no_move",1);	//���ᶳ��
        
        set_skill(0423,70);	//04233
        set_skill(0231,70);	//02310
        
        setup();
	set_char_type(FIGHTER_TYPE_2);
        set( "birthday", time() );
        set_enmity_flag(1);
}

int can_fight( object who ) 
{ 
        object owner;
        string leader, id;
	if( who->is_die() )
	{
		set_enemy(0);
		return 0;
	}
	if( who->is_npc() && objectp(owner = who->get_owner()) ) who = owner;
	if( who->is_npc() )
	{
		set_enemy(0);
		return 0;
	}
	
	return ::can_fight(who);
}

int can_be_fighted( object who ) 
{ 
        object owner;
        string leader, id;
	if( who->is_npc() && objectp(owner = who->get_owner()) ) who = owner;
	if( who->is_npc() )
	{
		set_enemy(0);
		return 0;
	}
	
	return ::can_be_fighted(who);
}

void heart_beat_walk()
{
	int i,x,y,z,x0,y0,z0,p,x1,y1;
	object enemy,me=this_object();

	if ( iRelax )
		return ;
	enemy = get_enemy();
	if ( objectp(enemy) )
	{		
		if ( enemy->is_die() )
			set_enemy(0);
		if ( gone_time(saytime) >=60 )
		{
			saytime = time();
			if(random(100) < 40)
			{
				SAY_CMD->say(me, "��������ȱ�ٿ��������Ƕ�������ô����Ȥ�ͼ�������Ķ���ɣ�"); 
			}
		}
	}
	else if ( RelaxTime == 0 )
	{
		RelaxTime = time();
	}
	if ( RelaxTime && gone_time(RelaxTime) >= 120 )
	{
		RelaxTime = 0;	
		init_fight_status();
		iRelax = 1;
		me->add_to_scene(get_z(me),141,53,4);
	}
	if( !get_effect(me, EFFECT_CHAR_NO_PF_0) )		//����Ĭ
	{
		set_effect(me, EFFECT_CHAR_NO_PF_0, 3600);
	}
	if( !get_effect(me, EFFECT_CHAR_WOUND_0) )		//������
	{
		set_effect(me, EFFECT_CHAR_WOUND_0, 3600);
	}	
	if( !get_effect(me, EFFECT_CHAR_FAINT_0) )		//��ѣ��
	{
		set_effect(me, EFFECT_CHAR_FAINT_0, 3600);
	}
	if( !get_effect(me, EFFECT_CHAR_SHUT_0) )		//������
	{
		set_effect(me, EFFECT_CHAR_SHUT_0, 3600);
	}
	if( !get_effect(me, EFFECT_CHAR_DREAM_0) )		//������
	{
		set_effect(me, EFFECT_CHAR_DREAM_0, 3600);
	}
	if( !get_effect(me, EFFECT_CHAR_LAZY_0) )		//���ӻ�
	{
		set_effect(me, EFFECT_CHAR_LAZY_0, 3600);
	}
	if ( gone_time(hptime) >= 15 )
	{
		hptime = time();
		//˲���ƶ�
		if ( objectp(enemy) )
		{
			z = get_z(enemy);z0=get_z(me);
			
			if( z == z0 && (p=distance_between(me, enemy)) < 20 && p > 1 )
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
			        if ( x1 && y1 && z )
			        {
		                        me->add_to_scene( z, x1, y1,4,9413);
		                        me->to_front_xy(x, y);
				}
			}
			
		}
	}

	::heart_beat_walk();	
}
void heart_beat_attack( )
{
	::heart_beat_attack( );
	
}

// �������ؼ���������
int perform_action( object who ) 
{
	int rate,x,y,z,i,size;
	object me = this_object(),*char,*nTarget;

	if( distance_between(me, who) > me->get_max_seek() ) 
	{
		return 0;	
	}
	RelaxTime = 0;
	iRelax = 0;
	if ( gone_time(pTime) > 60 )
	{
		pTime = time();
		char = get_range_object(get_z(me), get_x(me), get_y(me), 10, USER_TYPE) + get_range_object(get_z(me), get_x(me), get_y(me), 10, CHAR_TYPE) - ({ me,0 });
		nTarget = ({});
		for(i=0,size=sizeof(char);i<size;i++)
		{
			if ( me->can_fight(char[i]) )
				nTarget += ({char[i]});	
		}
		if ( size=sizeof(nTarget) )
		{
			SAY_CMD->say(me, "���ó�����Ĵ��������˾�����Ĳ����ˣ��Ұ���ı�������ɣ�");
			"skill/04/04233"->perform_action_npc(me,nTarget[random(size)]);
		}
		return 1;
	}
	
	if ( gone_time(pTime1) > 40 )
	{
		pTime1 = time();
		char = get_range_object(get_z(me), get_x(me), get_y(me), 10, USER_TYPE) + get_range_object(get_z(me), get_x(me), get_y(me), 10, CHAR_TYPE) - ({ me,0 });
		nTarget = ({});
		for(i=0,size=sizeof(char);i<size;i++)
		{
			if ( me->can_fight(char[i]) )
				nTarget += ({char[i]});	
		}
		if ( size=sizeof(nTarget) )
		{
			SAY_CMD->say(me, "ʲô������������Ĳ��ÿ����㻰��࣬���Ұ����㣡");
			"skill/02/02310"->perform_action_npc(me,nTarget[random(size)]);
		}
		return 1;
	}
}


// ��������λ����
void reset() 
{
       
}

// --------------------------------------------------------------- Զ�̵��� ----

// ��������������
void win_bonus( object who ) { __FILE__ ->win_bonus_callout( this_object(), who ); }

// ��������������(���߸���)
void win_bonus_callout( object me, object who )
{
        object owner, *team,map;
        int level, level2, exp, exp2, pot, alllevel;
        int i, size, status, time, flag;


	map = me->get("map");
	if ( map )
		map->add("beat_boss",1);
        if( !objectp( who = me->get_enemy_4() ) ) return;

        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return;

	drop_items(me,who);
	
        level = me->get_level();
        if( who->get_leader() && arrayp( team = who->get_team() ) && sizeof(team) > 1 )
        {
                team = me->correct_bonus_team(team);
                size = sizeof(team);
        }
        else
        {
        	team = ({who});
            	size = 1;
        }

        alllevel = 0;
        for( i = 0; i < size; i ++ ) if( team[i] )
        {
        	alllevel += team[i]->get_level();
        }
	if (alllevel==0) alllevel = 1;        	        		
	exp = 15000;
        for( i = 0; i < size; i ++ ) if( team[i] )
        {
                level2 = level - team[i]->get_level();
                exp2 = exp * team[i]->get_level()/alllevel;                        
                exp2 = me->correct_exp_bonus(level, level2, exp2) * who->get_online_rate() / 100;  

                if (exp2<5) exp2 = 5;
                team[i]->add_exp(exp2);
                team[i]->add_potential(100);	
                team[i]->add_log("#copyboss9", 1);
		team[i]->add_log("&copyboss9", exp2);
		team[i]->add_log("*copyboss9", 100);
	}
}

// ��������������
void drop_items( object me, object who )
{
	int x,y,z,p,i,rate,rate1;
	string *nTmp,id,owner;
	object item,leader;
	
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
        rate1 = me->correct_drop_rate( me->get_level() - who->get_level() ) * who->get_online_rate() / 100;

	if ( random(100) < rate1 )	//�ص�(�еȼ�����)
	{
		//65�������������װЬ��1��
		if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
		{
			item = new(WEAPON_FILE->get_suit_file(0,65,BOOTS_TYPE));
			if ( !item )
				return;
			item->set_record(1);
			TEAM_D->drop_item(item,who);
			item->set_user_id(owner);
		        item->add_to_scene(z, p / 1000, p % 1000);
		        item->set("winner", who);
		        item->set( "time", time() );	
		}
		//��Ǯ	
	         for(i=0;i<10;i++)
	         {
	                if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
	                {
	                        item = new( "/item/std/0001" );
	                        item->set_value( 400 );
	                        TEAM_D->drop_item(item,who);
				item->set_user_id(owner);
	                        item->add_to_scene(z, p / 1000, p % 1000);
	                        item->set("winner", who);
	                        item->set( "time", time() );
	                }
		}		
	}
	if ( random(100) < 15 * rate1/100 )
	{
               if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
	       {
			item = new( "quest/product2"->get_random_level_yellow_product(67,77) );
			TEAM_D->drop_item(item,who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set( "time", time() );
		}
	}

}

//ɱ��һ�����˼�2000��Ѫ
void stop_fight()
{
	object enemy;
	enemy = get_enemy();
	if ( enemy && enemy->get_hp()==0 )
	{
		SAY_CMD->say(this_object(), "��һ��ʧ��Ʒ�����Ƕ�������������");
		add_hp(2000);
	}
	::stop_fight();	
}