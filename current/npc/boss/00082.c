
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <skill.h>
#include <effect.h>
#include <music.h>

#define FILE_NPC "npc/boss/00084"

inherit NPC;
int iAtt,iWalk,hptime;
string *nFamily = ({"�һ�Դ","��ɽ","������","����","éɽ","����ɽ","������"});

void summon_guard();

// ��������������
int is_boss() { return 1; }

// �������Ƿ��ܽ���
int cannot_enter_city() { return 1; }

//����ս��״̬
int set_fight_status(int type,int level)
{
	object me=this_object();
	me->set("type",type);
	switch(type)
	{
	 case 1:  	//�����������
	        set_skill(3483,level);  
		set_skill(2512,level);
		set_skill(2416,level);
                
                set_attack_speed(10);  //�����ٶ� 
                set_walk_speed(3);     //�ƶ��ٶ�
                	
                add_dp(-1*get_dp()*25/100);    //�������
                add_max_hp(get_max_hp()*2000/100);	//�����Ѫ
                add_sp(get_sp()*200/100);	//����
                add_ap(get_ap()*320/100);      //������
                add_max_mp(get_max_mp()*200/100);  	//������
              
	 	break;
	 case 2:	//������ͷ����ͣ�
	 	set_skill(2216,level);  
		set_skill(2313,level);
		set_skill(2314,level);
                
                set_attack_speed(10);  //�����ٶ� 
                set_walk_speed(3);     //�ƶ��ٶ�
                	
                add_dp(get_dp()*300/100);    //�������
                add_max_hp(get_max_hp()*1000/100);	//�����Ѫ
                add_pp(-1*get_pp()*200/100);	//����
                add_ap(get_ap()*320/100);      //������
                add_max_mp(get_max_mp()*200/100);  	//������
	 	break;
	 case 3:	//�߷����������
	 	set_skill(4231,level);  
		set_skill(4232,level);
		set_skill(4234,level);
                set_skill(4243,level);
                
                set_attack_speed(11);  //�����ٶ� 
                set_walk_speed(3);     //�ƶ��ٶ�
                	
                add_dp(-1*get_dp()*25/100);    //�������
                add_max_hp(get_max_hp()*1000/100);	//�����Ѫ
               // add_attack_speed(get_attack_speed()*100/100)  //�ٶ�
                add_pp(get_pp()*150/100);	//����
                add_cp(get_cp()*400/100);      //��������
                add_max_mp(get_max_mp()*2400/100);  	//������
	 	break;
	 case 4:	//��Ѫ�ͣ�
	 	set_skill(2118,level);  
		set_skill(2114,level);
		set_skill(2115,level);
                                
                set_attack_speed(10);  //�����ٶ� 
                set_walk_speed(3);     //�ƶ��ٶ�
                	
                add_dp(-1*get_dp()*20/100);    //�������
                add_max_hp(get_max_hp()*4000/100);	//�����Ѫ
                add_pp(-1*get_pp()*20/100);	//����
                add_ap(get_ap()*360/100);      //������
                add_max_mp(get_max_mp()*200/100);  	//������
	 	break;
	 case 5:	//��Ѫ������߷����ͣ�
	 	set_skill(2616,level);  
		set_skill(2615,level);
		                                
                set_attack_speed(13);  //�����ٶ� 
                set_walk_speed(3);     //�ƶ��ٶ�
                	
                add_dp(get_dp()*45/100);    //�������
                add_max_hp(get_max_hp()*1200/100);	//�����Ѫ
                //add_attack_speed(get_attack_speed()*300/100)  //�ٶ�
                add_pp(get_pp()*180/100);	//����
                add_ap(get_ap()*200/100);      //������
                add_max_mp(get_max_mp()*400/100);  	//������
	 	break;
	 case 6:	//ǿ���ͼ��ٻ���
	 	set_skill(4143,level);  
		set_skill(4144,level);
		                                
                set_attack_speed(13);  //�����ٶ� 
                set_walk_speed(3);     //�ƶ��ٶ�
                	
                add_dp(get_dp()*45/100);    //�������
                add_max_hp(get_max_hp()*1200/100);	//�����Ѫ
               // add_attack_speed(get_attack_speed()*300/100)  //�ٶ�
                add_pp(get_pp()*45/100);	//����
                add_ap(get_ap()*400/100);      //������
                add_max_mp(get_max_mp()*600/100);  	//������
	 	break;	
	}
//	tell_user(this_player(),"set_fight_status type=%d",type);
		
}

// ���������촦��
void create()
{
        object me=this_object();
        set_name( "��Ĺʯ��");
        set_char_picid(1267);   
	set_level(100);
	set_max_hp(1000);
	set_max_mp(1000);
	set_ap(100);
	set_effect(me, EFFECT_CHAR_BUSY, 15);
	call_out("do_fight", 15);
        setup();
        set_char_type(FIGHTER_TYPE_2); 
}

//15��󸴻��ʼս��
void do_fight() 
{
	object me = this_object();
	set_effect(me, EFFECT_CHAR_BUSY, 0);
	me->add_to_scene(get_z(me), get_x(me), get_y(me));
}

// �������ؼ���������
int perform_action( object who ) 
{
	int rate,type;
	object me = this_object();
	
	if( get_z(who)!=get_z(me) || !inside_screen_2(me, who)  )
		return 0;
	rate = random(100);
	type=me->get("type");	
	switch(type)
	{
	case 1:
		if ( rate < 10 )
			return PF_FILE_03483->perform_action_npc(me, who);
		else if ( rate < 34 )
			return PF_FILE_02512->perform_action_npc(me, who);
		else if ( rate < 40 )
			return PF_FILE_02416->perform_action_npc(me, who);			
		break;
	case 2:
		if ( rate < 16 )
			return PF_FILE_02216->perform_action_npc(me, who);
		else if ( rate < 32 )
			return PF_FILE_02313->perform_action_npc(me, who);
		else if ( rate < 48 )
			return PF_FILE_02314->perform_action_npc(me, who);
		break;			
	case 3:	
		if( get_effect(me, EFFECT_CHAR_NO_PF) ) return 0;
		if ( get_effect(me, EFFECT_CHAR_CHANGE) < 1)
		{
			PF_FILE_04251->cast_done_npc(me);			
		}
		if ( rate < 70 )
			return PF_FILE_04231->perform_action_npc(me, who);
		else if ( rate < 90 )
			return PF_FILE_04232->perform_action_npc(me, who);
		else if ( rate < 97 )
			return PF_FILE_04234->perform_action_npc(me, who);
		else
			return PF_FILE_04243->perform_action_npc(me, who);	
		break;
	case 4: 
		if( !me->get_perform("03173") ) 
		{
			PF_FILE_03173->perform_action_npc(me,who);
		}
		if ( rate < 10 )
			return PF_FILE_02118->perform_action_npc(me, who);
		else if ( rate < 26 )
			return PF_FILE_02114->perform_action_npc(me, who);
		else if ( rate < 38 )
			return PF_FILE_02115->perform_action_npc(me, who);
		break;
	case 5:
		if( !me->get_effect(me, EFFECT_USER_HURT) ) 
		{
			PF_FILE_03632->cast_done_npc(me);
		}
		if ( rate < 20 )
			return PF_FILE_02616->perform_action_npc(me, who);
		else if ( rate < 40 )
			return PF_FILE_02615->perform_action_npc(me, who);
		break;
	case 6:
		summon_guard();
		if( get_effect(me, EFFECT_CHAR_NO_PF) ) return 0;
		if ( rate < 12 )
			return PF_FILE_04143->perform_action_npc(me, who);
		else if ( rate < 24 )
			return PF_FILE_04144->perform_action_npc(me, who);
		break;		
	}
	return 0;
}


// --------------------------------------------------------------- Զ�̵��� ----
//��������
void win_bonus( object who )
{
	object owner,*team,*team2,map;
	object me = this_object();
	string id,id2;
	int i,size,level;
        if( !me->can_be_fighted(who) ) return;
        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return;
	team = who->get_team();
	if ( sizeof(team) < 1 ) team = ({who});
        team = me->correct_bonus_team( team );
        if( ( size = sizeof(team) ) < 1 ) return;
	if( !objectp( map = get_map_object(get_z(me)) ) || !map->is_scene() ) return;	
        for(i=0;i<size;i++)
        {
        	team[i]->add_exp(1000+random(501));
        }
        __FILE__->drop_items(me,who);
        return;
}


// ��������������

void drop_items( object me, object who )
{
	int x,y,z,p,i,rate,rate1,level;
	string *nTmp,id,owner,file;
	object item,leader;
	
	z = get_z(me);  x = get_x(me);  y = get_y(me);
	level=me->get_level();
	if(!level) level=30;
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
	rate = random(100);
	if ( rate < rate1 ) //�ص�
	{
		if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )  //���������ɫװ��1��
                {
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,level,HEAD_TYPE+random(6));
			if ( sizeof(nTmp) )
			{	
				item = new(nTmp[random(sizeof(nTmp))]);
				if ( !item )
					return;
				ITEM_EQUIP_D->init_equip_prop_1(item);
				TEAM_D->drop_item(item,who);
				item->set_user_id(owner);
			        item->add_to_scene(z, p / 1000, p % 1000);
			        item->set("winner", who);
			        item->set( "time", time() );	
			 }
                }
		for(i=0;i<5;i++)	//5��5000��
	        {	
	        	if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
	                {
	                        item = new( "/item/std/0001" );
	                        item->set_value( 5000 );
	                        TEAM_D->drop_item(item,who);
				item->set_user_id(owner);
	                        item->add_to_scene(z, p / 1000, p % 1000);
	                        item->set("winner", who);
	                        item->set( "time", time() );
	                      
	                }
		}
		
	}
	p = get_valid_xy(z, x, y, IS_ITEM_BLOCK);
	if ( !p )
		return;
	rate = random(10000);
	if ( rate < 200 * rate1 / 100 )	//level����������ɽ�ɫװ��%2
	{
		nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,100,HEAD_TYPE+random(6));
		if ( sizeof(nTmp) )
		{	
			item = new(nTmp[random(sizeof(nTmp))]);
			if ( !item )
				return;
			ITEM_EQUIP_D->init_equip_prop_3(item);
			TEAM_D->drop_item(item,who);
			item->set_user_id(owner);
		        item->add_to_scene(z, p / 1000, p % 1000);
		        item->set("winner", who);
		        item->set( "time", time() );	
		}	
	}
	else if ( rate < 2200  * rate1 / 100)		//һ����ʯ%20
	{
		 if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
	         {
		         item = new(STONE_FILE->get_diamond_file());
		         item->set_level(1);
		         TEAM_D->drop_item(item,who);
			 item->set_user_id(owner);
		         item->add_to_scene(z, p / 1000, p % 1000);
		         item->set("winner", who);
		         item->set( "time", time() );
	         }		
	}
	else if ( rate < 4400  * rate1 / 100 )		//1����Ӧ����ɽ����飺20%
	{
 		if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
	        {
		         item = new(BOOK_FILE->get_book_file());
		         TEAM_D->drop_item(item,who);
			 item->set_user_id(owner);
		         item->add_to_scene(z, p / 1000, p % 1000);
		         item->set("winner", who);
		         item->set( "time", time() );
	        }
	}	
	else if ( rate < 9400  * rate1 / 100)		//�ϲε�3����50% 2����ͨ�ر�ͼ��50%
	{
		rate=random(2);
		if(rate==0) //�ر�ͼ
		{
			for(i=0;i<5;i++)
			{
				switch( random(1) )
	                        {
	                        case 0 : file = "item/std/8000";  break;
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
		}
		if(rate==1)  //�ϲε�3��
		{
			for(i=0;i<3;i++)
			{
				switch( random(1) )
	                        {
	                        case 0 : file = "/item/91/9167";  break;
	
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
		}
	}	
	
}

//�Զ���������������
void heart_beat_walk()
{
	string robber;
	object *member,who,owner;
	object me = this_object(),enemy;
	int x,y,z,x0,y0,z0,x1,y1,p,i;
	//3�봦��һ��
	if ( (iWalk++)%3 )
	{
		::heart_beat_walk();
		return;		
	}
	if ( gone_time(hptime) >= 20+random(21) )
	{
		hptime = time();
		//˲���ƶ�
		enemy = get_enemy();
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
	member = get_range_object_2(me, me->get_max_seek(), CHAR_TYPE)+get_range_object_2(me, me->get_max_seek(), USER_TYPE)-({me});
	if ( sizeof(member) != 0 )
	{
		robber = sprintf( "%x#", getoid(me) );
		foreach(who in member)
		{
				
			if ( who->is_die() ) 
				continue;
			if( (owner = who->get_owner()) && (owner->get_task("robber") != robber) ) 
			{
				continue;	
			}
			else if (  !(owner = who->get_owner()) && who->get_task("robber") != robber )
				continue;
			me->set_main_enemy(who);
			::heart_beat_walk();
			return;
		}		
	}
	owner =  me->get_enemy();
	if ( !objectp(owner) )
		return ;
        if( get_z(owner)!=get_z(me) || distance_between(me, owner) > 20 )  
        {
		me->set_enemy(0);
		return ;
	}

}


void heart_beat_attack( )
{
	string robber;
	object who;
	object me = this_object();
	//3�봦��һ��
	if ( (iAtt++)%3 )	
	{
		::heart_beat_attack();
		return;		
	}	
	who = me->get_enemy();
	if ( !objectp(who) )
		return ;
        if( get_z(who)!=get_z(me) || distance_between(me, who) > 20 || !who->can_fight(me) )  
        {
		me->set_enemy(0);
		return ;
	}	

	::heart_beat_attack();

}


//�ٻ�
void summon_guard()
{
	int i,size,x,y,z,count,p,level,mp;
	object npc,me=this_object();

	x = get_x(me);y = get_y(me);z = get_z(me);
	mp=me->get_mp();
	level=get_level()-5;
	for(i=0;i<5;i++)
	{
		if ( objectp(get(sprintf("guard%d",i))) )
			continue;
		p = get_valid_xy(z, x + random(10) - 5, y + random(10) - 5, IS_CHAR_BLOCK);
		if ( !p )
			continue;
		if(!(mp>=10)) continue;
		npc = new(FILE_NPC);	
		if ( !npc )
			break;
		me->add_mp(-10);
		set(sprintf("guard%d",i),npc);
		add("guard",({npc}));
		NPC_ENERGY_D->init_level(npc,level);
		npc->set_fight_status(level);
		npc->add_to_scene( z, p / 1000, p % 1000);
		npc->set_owner(me);
		NPC_SLAVE_D->find_enemy(npc);    // Ѱ�ҵ���
		send_user( get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(npc), 
                        41311, 1, OVER_BODY, 41312, 1, OVER_BODY, 41313, 1, UNDER_FOOT, PF_ONCE );
	}
	
}