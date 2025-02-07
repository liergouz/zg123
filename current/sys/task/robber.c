
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <music.h>
#include <task.h>

#define ROBBER          "/npc/task/8210"
//#define _ROBBER_TEST

void clear_task_desc(object who);
void send_task_list(object who);

// 函数：生成二进制码
void SAVE_BINARY() { }

// 函数：对话处理
void do_look( object who, object me )
{
        object npc;
        string robber,result;

        int id = getoid(me);
        string cmd1 = sprintf( "talk %x# task\n", id );
        string cmd2 = sprintf( "talk %x# info\n", id );
	
	if ( who->get_task("robber.bonus") && (robber = who->get_task("robber.name")) && stringp(robber) )
                result = me->get_name() + "：\n    来打官司的么？那就得意思意思一下，好让我给你美言几句。你问我是做什么的？我是本衙门的师爷，负责所有案件的跟踪调查追捕，知道了没？\n" 
                        ESC "剿灭悍匪" + robber+"\n" + cmd2;                       
	else if(     stringp( robber = who->get_task("robber") ) 
        &&    ( npc = find_char(robber) ) && npc->is_robber() )
                result = me->get_name() + "：\n    来打官司的么？那就得意思意思一下，好让我给你美言几句。你问我是做什么的？我是本衙门的师爷，负责所有案件的跟踪调查追捕，知道了没？\n" 
                        ESC "剿灭悍匪" + npc->get_name()+"\n" + cmd2;                      
        else    result = me->get_name() + "：\n    来打官司的么？那就得意思意思一下，好让我给你美言几句。你问我是做什么的？我是本衙门的师爷，负责所有案件的跟踪调查追捕，知道了没？\n" 
                        ESC "协助剿匪\n" + cmd1;
//	if ( who->get_legend(TASK_NEWBIE_00, 9) && !who->get_legend(TASK_NEWBIE_00, 10) )
	if ( who->get_legend(TASK_2_00,12) && !who->get_legend(TASK_2_00,13) ) 
		result += sprintf(ESC HIY "前来拜访\ntalk %x# visit.1\n",getoid(me));
	if ( who->get_legend(TASK_2_00,13) && !who->get_legend(TASK_2_00,14) ) 
		result += sprintf(ESC HIY "拜访尉迟老镖头\ntalk %x# visit.3\n",getoid(me));
	result += ESC "离开。\nCLOSE\n" ;
	if ( stringp(result) )
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), result);
}

// 函数：开始任务
void do_task_start( object who, object me )
{
        object *team, npc, map, item;
        string *member, robber,name;
        int level, min, max, i, size;
        int z, x, y, p;

        if( !arrayp( team = who->get_team() ) || !who->is_leader() )
        {
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + "：\n    你们的头呢？叫他来找我。你年纪轻，还不能担此大任，我怕你负责不起。\n" );
                return;
        }

        if(     stringp( robber = who->get_task("robber") ) 
        &&    ( npc = find_char(robber) ) && npc->is_robber() )
        {
                send_user( who, "%c%s", '!', "请先完成手上的剿匪任务吧。" );
                return;
        }

        if( ( size = sizeof(team) ) < 2 )
        {
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + "：\n    剿匪任务最少两人参与。" );
                return;
        }
        name="";
        for( i = 0; i < size; i ++ ) if( team[i] && team[i] != who && inside_screen_2(who,team[i]) )
        {
        	if ( team[i]->get_task("robber.bonus")  || 
        		(     stringp( robber = team[i]->get_task("robber") ) && ( npc = find_char(robber) ) && npc->is_robber() ) ) 
        	{
        		if(sizeof(name))
        		{
        			name += "、";
        		}
        		name += team[i]->get_name();
        		continue;
        	}
        }
        if ( sizeof(name) )
        {
        	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf(me->get_name() + "：\n    由于你们队伍中%s没有完成上轮任务，所以该任务不能领取！\n"ESC"离开" ,name));
        	return;
        }

        min = 10000;  max = 0;
        for( i = 0; i < size; i ++ ) if( team[i] )
        {
                p = team[i]->get_level();
                if( p < min ) min = p;
                if( p > max ) max = p;
        }
        if( min < 30 )
        {
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + "：\n    哎呀！你们当中有人还不够级别参与到这次任务中，最低等级要求为30级哦！\n" );
                return;
        }
        if( max > min + 10 )
        {
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + "：\n    你们的队伍如此良莠不齐，我可不放心把此重任交给你们！等你们的等级差别小于10级了再来找我吧！" );
                return;
        }

        if( gone_time(who->get_task("robber.time")) < 180 )
        {
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + "：\n    可惜，刚刚有人先你一步，协助我去剿匪了，现在很太平，没有作恶的匪徒，你过段时间再来吧！\n" 
                	ESC "离开。\nCLOSE\n" );
                return;
        }
        level = who->get_level();    // 队长等级

        if( !( p = XY_D->get_city_point( -1, IS_CHAR_BLOCK ) ) ) return;

        z = p / 1000000;  x = ( p % 1000000 ) / 1000;  y = p % 1000;

        if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;
	name = NPC_NAME_D->get_robber_name();
        item = who->get_equip(HAND_TYPE);
	if (item && item->get_item_number()==10001078)
	{	
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + 
			sprintf(": \n    这位少侠可真是帮俺大忙了。最近"HIR"%s"NOR"一带又出现了一个悍匪"HIR"%s"NOR"，其杀人越货无恶不作，甚是猖獗。现在衙门人手严重不足，只希望少侠能出手相助。如果能成功剿灭这贼，本师爷会给少侠丰厚报酬的。\n" ,map->get_name(),name) +
			 ESC "接受\n" + sprintf("talk %x# accept\n",getoid(me)) +
	                 ESC "离开。\n" + sprintf("talk %x# visit.cancel\n",getoid(me)) );
	}
	else
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + 
			sprintf(": \n    这位少侠可真是帮俺大忙了。最近"HIR"%s"NOR"一带又出现了一个悍匪"HIR"%s"NOR"，其杀人越货无恶不作，甚是猖獗。现在衙门人手严重不足，只希望少侠能出手相助。如果能成功剿灭这贼，本师爷会给少侠丰厚报酬的。\n" ,map->get_name(),name) +
			 ESC "接受\n" + sprintf("talk %x# accept\n",getoid(me)) +
	                 ESC "离开。\nCLOSE\n" );
		
	}
	who->set("robber.name",name);
	who->set("robber.x",x);
	who->set("robber.y",y);
	who->set("robber.z",z);
	who->set_task("robber.time",time());
}
//接受任务
void accept_task( object who, object me )
{
        object *team, npc, map;
        string robber,name,teamname;
        int level, min, max, i, size;
        int z, x, y, p;
        
       	name = who->get("robber.name");
	x = who->get("robber.x",x);
	y = who->get("robber.y",y);
	z = who->get("robber.z",z);
	if ( !stringp(name) ) return ;
	if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;	
		
	who->delete("robber.name");
	who->delete("robber.x");
	who->delete("robber.y");
	who->delete("robber.z");
	who->delete_task("robber.time");	
	
       if( !arrayp( team = who->get_team() ) || !who->is_leader() )
        {
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + "：\n    你们的头呢？叫他来找我。你年纪轻，还不能担此大任，我怕你负责不起。\n" );
                return;
        }

//        if(     stringp( robber = who->get_task("robber") ) 
//        &&    ( npc = find_char(robber) ) && npc->is_robber() )
//        {
//                send_user( who, "%c%s", '!', "请先完成手上的剿匪任务吧。" );
//                return;
//        }

        if( ( size = sizeof(team) ) < 2 )
        {
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + "：\n    剿匪任务最少两人参与。" );
                return;
        }
        teamname="";
        for( i = 0; i < size; i ++ ) if( team[i] && team[i] != who && inside_screen_2(who,team[i]) )
        {
        	if ( team[i]->get_task("robber.bonus")  || 
        		(     stringp( robber = team[i]->get_task("robber") ) && ( npc = find_char(robber) ) && npc->is_robber() ) ) 
        	{
        		if(sizeof(teamname))
        		{
        			teamname += "、";
        		}
        		teamname += team[i]->get_name();
        		continue;
        	}
        }
        if ( sizeof(teamname) )
        {
        	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf(me->get_name() + "：\n    由于你们队伍中%s没有完成上轮任务，所以该任务不能领取！\n"ESC"离开" ,teamname));
        	return;
        }
        min = 10000;  max = 0;
        for( i = 0; i < size; i ++ ) if( team[i] )
        {
                p = team[i]->get_level();
                if( p < min ) min = p;
                if( p > max ) max = p;
        }
        if( min < 30 )
        {
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + "：\n    哎呀！你们当中有人还不够级别参与到这次任务中，最低等级要求为30级哦！\n" );
                return;
        }
        if( max > min + 10 )
        {
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + "：\n    你们的队伍如此良莠不齐，我可不放心把此重任交给你们！等你们的等级差别小于10级了再来找我吧！" );
                return;
        }

        level = who->get_level();    // 队长等级

        npc = new( ROBBER );
        if ( !npc ) return;
        level += 5;  npc->set("level", level);
	npc->set_name("悍匪"+name);
	NPC_ENERGY_D->init_level(npc, level);
	npc->set_max_seek(8);

	p = random(100);
	if ( p < 20)	//低物防高敏型
	{
		npc->set_skill(348,level);
		npc->set_skill(251,level);
		npc->set_skill(241,level);
		npc->set_char_picid(8011);
                npc->set_walk_speed(3);
                npc->set_attack_speed(10);	
                npc->add_dp(-1*npc->get_dp()/4);
                npc->add_max_hp(npc->get_max_hp()*41/2);	
                npc->add_sp(npc->get_sp()*11);
                npc->add_ap(npc->get_ap()*4/5);
                npc->add_mp(npc->get_mp()/2);  
                npc->set("robber.type",1);              		
	}
	else if ( p < 40 )	//高物防低法防型
	{
		npc->set_skill(221,level);
		npc->set_skill(231,level);
		npc->set_char_picid(0252);
                npc->set_walk_speed(3);
                npc->set_attack_speed(10);	
                npc->add_dp(npc->get_dp()*3);
                npc->add_max_hp(npc->get_max_hp()*21); 	
                npc->add_pp(-1*npc->get_pp()*3/10);                
                npc->add_ap(npc->get_ap()*4/5);                
                npc->add_mp(npc->get_mp()/2);  
                npc->set("robber.type",2);              		
	}
	else if ( p < 60 )	//高法防低物防型
	{
		npc->set_skill(424,level);
		npc->set_skill(423,level);
		npc->set_skill(425,level);
		npc->set_char_picid(8010);
                npc->set_walk_speed(4);
                npc->set_attack_speed(10);	
                npc->add_dp(-1*npc->get_dp()/4);
                npc->add_max_hp(npc->get_max_hp()*22); 	
                npc->add_sp(npc->get_sp());  
                npc->add_pp(npc->get_pp()*3/2);                
                npc->add_cp(npc->get_cp());
		npc->add_mp(npc->get_mp()*6);
                npc->set("robber.type",3);              		
	}	
	else if ( p < 70 )	//长血型：拳脚类
	{
		npc->set_skill(317,level);
		npc->set_skill(211,level);
		npc->set_char_picid(8000);
                npc->set_walk_speed(3);
                npc->set_attack_speed(10);	
                npc->add_dp(-1*npc->get_dp()/5);        
                npc->add_max_hp(npc->get_max_hp()*37); 
                npc->add_pp(-1*npc->get_pp()/5);                
                npc->add_cp(npc->get_cp()/2);                 
                npc->add_ap(npc->get_ap()*9/10);  
                npc->set("robber.type",4);              		
	}
	else if ( p < 90 )	//长血高物防高法防型：远程暗器类
	{
		npc->set_skill(261,level);
		npc->set_char_picid(8012);
                npc->set_walk_speed(3);
                npc->set_attack_speed(10);	
		npc->add_dp(npc->get_dp()*9/20);
		npc->add_max_hp(npc->get_max_hp()*65/2); 
 		npc->add_sp(npc->get_sp()*3);
 		npc->add_pp(npc->get_pp()*9/5);
 		npc->add_mp(npc->get_mp());
 		npc->add_ap(npc->get_ap()/2);
                npc->set("robber.type",5);              		
	}
	else 	//强攻型加召唤
	{
		npc->set_skill(414,level);
		npc->set_char_picid(8013);
                npc->set_walk_speed(3);
                npc->set_attack_speed(8);	
                npc->add_dp(npc->get_dp()*10);
                npc->add_ap(npc->get_ap()); 
                npc->add_max_hp(npc->get_max_hp()*13/2);                 
                npc->add_sp(npc->get_sp()*3);  
                npc->add_pp(npc->get_pp()*9/20);      
                npc->add_mp(npc->get_mp()*3/2);  
                npc->set("robber.type",6);              		
	}	

        npc->add_to_scene(z, x, y, 3);
        npc->set("user", ({ sprintf( "%d", who->get_number() ) }));
        map->add_reset(npc);    // 加入复位列表
        robber = sprintf( "%x#", getoid(npc) );
//	if( team[i]->get_task("robber") ) team[i]->delete_task("robber#");
	who->set_task("robber", robber);
	send_task_list(who);
        size = sizeof(team);
        for( i = 0; i < size; i ++ ) if( team[i] && team[i] != who && inside_screen_2(who,team[i]) )
        {
        	if ( team[i]->get_task("robber.bonus") ) continue;
        	send_user( team[i], "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + 
		sprintf(": \n    %s已经接受了剿匪任务，你是否一同协助？\n",who->get_name()) +
		 ESC "接受\n" + sprintf("talk %x# join\n",getoid(me)) +
                 ESC "离开。\nCLOSE\n" );
                 team[i]->set("robber.join",sprintf( "%d",who->get_number()));
                 team[i]->set("robber.robber",robber);
        } 
}

// 函数：取消任务
void do_task_cancel( object who, object me )
{
        object *team, npc;
        string robber;
        int time;

        if(    !stringp( robber = who->get_task("robber") )
        ||     !objectp( npc = find_char(robber) )
        ||     !npc->is_robber() )
        {
                send_user( who, "%c%s", '!', "你们没有领取剿匪任务。" );
                return;
        }

        if( !arrayp( team = who->get_team() ) || !who->is_leader() )
        {
                send_user( who, "%c%s", '!', "只有队长才能取消剿匪任务。" );
                return;
        }

        if( ( time = gone_time( npc->get("birthday") ) ) < 180 )    // ３分钟
        {
                send_user( who, "%c%s", '!', sprintf( "还有 %d 秒才能取消剿匪任务。", 180 - time ) );
                return;
        }

        who->add_hp( - who->get_hp() / 2 );    // 气血、法力减少一半
        who->add_mp( - who->get_mp() / 2 );

        team->delete_task("robber");
//        team->set_task("robber#", -1);    // 任务完成数

        send_user( who, "%c%s", ':', sprintf( "%s：\n我们已经将%s抓起来了，不用再劳烦你们了。\n", 
                me->get_name(), npc->get_name() ) );

        npc->remove_from_scene();
        destruct(npc);

        return;
}
//加入任务
void join_task( object who, object me )
{	
	string join,robber,*member;
	object *team,Leader,npc;

	if( !arrayp( team = who->get_team() ) || who->is_leader() )	return ;		
	join = who->get("robber.join");
	robber = who->get("robber.robber");
	if ( !stringp(join) || !stringp(robber) || join != who->get_leader() )	return ;		
	Leader = find_player(join);
	if ( !Leader )	return ;		
	if ( Leader->get_task("robber") != robber ) return ;
	npc = find_char(robber);
	if ( !npc || !npc->is_robber())	return;
	member = npc->get("user");
	if ( !arrayp(member) )	return;
	member += ({ sprintf( "%d", who->get_number() ) });
	npc->set("user",member);
//	if( who->get_task("robber") ) 
//		who->delete_task("robber#");
	who->set_task("robber", robber);	
	who->delete("robber.join");
	who->delete("robber.robber");
	send_task_list(who);
}

void task_info( object who, object me )
{
	int z;
	string robber;
	object npc,map;

	if ( who->get_task("robber.bonus") )
	{
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + "：\n    恭喜你，得到了一次不错的锻炼，能力也得到了提高，同时也获得了我们的肯定，下次有这样的机会，我还是希望你能来协助我们！\n" 
                        ESC "完成任务\n" + sprintf( "talk %x# bonus\n", getoid(me) ) +                        
                        ESC "离开。\nCLOSE\n" );	
		return ;	
	}
        robber = who->get_task("robber");        		
	npc = find_char(robber);
	if ( !npc || !npc->is_robber())	return;
	z = get_z(npc);
	if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;
        send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + 
        	sprintf("：\n    事情进行得怎么样了？那个悍匪"HIR"%s"NOR"应该就在"HIR"%s"NOR"一带出没。如果你手中有“缉捕公文”，应该很容易就能找到那贼。\n" 
        	ESC "离开。\nCLOSE\n",npc->get_name(),map->get_name() ) );	
 
}

// 函数：对话处理
void task_bonus( object who, object me )
{
	int level,level2,exp2,pot2,i,size,exp,pot,money;
	string name,robber,file;
	object item,item1;
	
        level = who->get_task("robber.level");
        name = who->get_task("robber.name");
        robber = who->get_task("robber");
        
        exp = level * 30;
        pot = level * 21 /5;

        if ( who->get_task("robber.bonus")==0 ) return;
        if( ( level2 = who->add_task("robber#", 1) ) >= 10 ) who->delete_task("robber#");
        level2 --;
	if ( level2 == 9  )	//完成10次的奖励
	{
		i = random(100);
		if ( i<30 )	//装备
		{
			if ( random(2) )
				item = new(WEAPON_FILE->get_weapon_file_2(who->get_level()>100?100:who->get_level()));
			else
				item = new(ARMOR_FILE->get_armor_file_2(who->get_level()>100?100:who->get_level()));
			i = random(10000);
			if ( i < 1000 )
				ITEM_EQUIP_D->init_equip_prop_1(item);
			else if ( i < 1005 )
				ITEM_EQUIP_D->init_equip_prop_3(item);
			i = item->move(who,-1);
			if ( i )
			{
				item->add_to_user(i);
				send_user(who,"%c%s",'!',"你得到了 "HIY+item->get_name());
			}
			else
			{
				send_user(who,"%c%s",'!',"你身上的物品太多了不能得到额外的奖励");
				destruct(item);
			}
		}
		else if ( i<80 )	//中间产品
		{
	                file = "sys/item/product"->get_random_mid_product();
	                if( load_object(file) )
	                {
	                	item = new(file);
				i = item->move(who,-1);
				if ( i )
				{
					item->add_to_user(i);
					send_user(who,"%c%s",'!',"你得到了 "HIY+item->get_name());
				}
				else
				{
					send_user(who,"%c%s",'!',"你身上的物品太多了不能得到额外的奖励");
					destruct(item);
				}
	                }
        	}
        	else if ( i<81 )	//精元丹
        	{
                	item = new("item/44/4488");
                	i = "quest/pet"->get_drop_skill1();
			if ( i )
				item->set("special",sprintf("%d",i));
			i = item->move(who,-1);
			if ( i )
			{
				item->add_to_user(i);
				send_user(who,"%c%s",'!',"你得到了 "HIY+item->get_name());
			}
			else
			{
				send_user(who,"%c%s",'!',"你身上的物品太多了不能得到额外的奖励");
				destruct(item);
			}        		
        	}
        	if (random100()<5) "/quest/box"->give_box(who);
	}
        who->delete_task("robber");    // 完成任务，删除标志
	who->delete_task("robber.bonus"); 
	who->delete_task("robber.level"); 
	who->delete_task("robber.name"); 
	
	exp2 = exp;
	for(i=0;i<level2;i++)
		exp2 = exp2 * 115 / 100;
        pot2 = pot + pot / 10 * level2;
	exp2 = exp2 * who->get_online_rate() / 100;
        who->add_exp(exp2);    // add_exp(exp2, 1);
        if ( item1=who->get_equip(HAND_TYPE) )
	        pot2 += item1->add_potential(pot2,who);
	if ( who->get_vip() )
		pot2 += pot2;	      
	pot2 = pot2 * who->get_online_rate() / 100;
        who->add_potential(pot2);
        money = money * who->get_online_rate()/100;
	who->add_cash(money);
	who->log_money("悍匪", money);                
	"/sys/sys/count"->add_income("robber", money);
	"/sys/sys/count"->add_task("师爷杀囚", 1);
	
        who->add_log("&robber", exp2);
        who->add_log("*robber", pot2);
        who->add_log("#robber", 1);
        who->add_log("$robber", money);
        

        send_user( who, "%c%w", 0x0d, MUSIC_TASK );
        //tip
        send_user( who, "%c%s", ';',sprintf("您参与击毙%s任务，经验 %+d, 潜能 %+d, 金钱 +500。", name, exp2, pot2 ));
        clear_task_desc(who);
}

void task_giveup(object who,int iKind)
{
	object npc, item;
	string id,*member;

	if ( who->get_task("robber.bonus") )  
	{
	 	send_user( who, "%c%s", '!', "任务已经完成了，请向师爷报告。" );	
	 	return ;
	}	
        if( gone_time(who->get_task("robber.time")) < 180 )
        {
		item = who->get_equip(HAND_TYPE);
		if (item && item->get_item_number()==10001078)
		{
                        send_user( who, "%c%c%s", 0x59, 1, sprintf("你是否使用'瞒天过海符'来消除你的任务间隔时间？\n"
                        	ESC "%c\n"ESC"use %x# robber2\n"
                                , 1, getoid(item) ) );			
			return;
		}
		send_user( who, "%c%s", '!', "请稍后再取消任务" );
		return;	
        }	
	id = who->get_task("robber");
	who->delete_task("robber");
	             
        clear_task_desc(who);
        if(    !stringp( id )
        ||     !objectp( npc = find_char(id) )
        ||     !npc->is_robber() )
        { 
                return;
        }
        member = npc->get("user");
        id = sprintf("%d",who->get_number());
        member -= ({id});
        if ( sizeof(member) == 0 )
        {
	        npc->remove_from_scene();
	        destruct(npc);        	
        }
        else
        	npc->set("user", member);
                
}

void send_task_list(object who)
{
	string id;
	object npc;
	
	clear_task_desc(who);
	if( who->get_task("robber.bonus") )
	{
                send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_ROBBER,"师爷任务" );     
                send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_ROBBER,1,sprintf("剿灭%s(已完成)",who->get_task("robber.name")) );                  		
	}	
	else if (     stringp( id = who->get_task("robber") ) 
        &&    ( npc = find_char(id) ) && npc->is_robber() )    
        {
                send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_ROBBER,"师爷任务" );     
                send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_ROBBER,1,sprintf("剿灭%s",npc->get_name()) );                  
        }
	
}

void clear_task_desc(object who)
{
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 3,TID_ROBBER,1,"" );
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_ROBBER,1,"");
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_ROBBER,"");
}

void do_visit(object who,object npc,string arg)
{
	int i,exp,pot,money;
	object item;
//	if ( !who->get_legend(TASK_NEWBIE_00, 9) || who->get_legend(TASK_NEWBIE_00, 10) )
//		return ;

	if (arg=="cancel")
	{
	        item = who->get_equip(HAND_TYPE);
		if (item && item->get_item_number()==10001078)
		{	
			send_user( who, "%c%c%s", 0x59, 1, sprintf("你是否使用'瞒天过海符'来消除你的任务间隔时间？\n"
	                	ESC "%c\n"ESC"use %x# robber\n"
	                        , 1, getoid(item) ) );						
		}
		return;
	}
	if ( who->get_legend(TASK_2_00,12) && !who->get_legend(TASK_2_00,13) ) 
	{
		i = to_int(arg);
		if ( i == 1 )
			send_user( who, "%c%c%w%s", ':',3,npc->get_char_picid(), sprintf("%s:\n    呵呵，相信你又是听说了那些传言，所以来看看我到底是个怎样的人吧？现在你看见了，我可不是长着三头六臂的怪物，我还不是和普通人一样，没什么了不起的，倒是最近这周边一带出现了不少匪徒，让人头疼啊！\n"ESC"完成任务\ntalk %x# visit.2\n",npc->get_name(),getoid(npc)));	
		else if ( i == 2 )
		{
			TASK_LEGEND_D->task_finish(who);
			exp = 300 ;
			pot = 35 ;
			money = 500 ;
			who->set_legend(TASK_2_00,13);
			who->add_exp(exp);
			who->add_potential(pot);
			who->add_cash(money);
			send_user(who,"%c%s",';',sprintf("拜访师爷 经验 %d 潜能 %d 金钱 %d",exp,pot,money));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,16,"" );
			npc->do_visit(3);
		}
	}
	if ( who->get_legend(TASK_2_00,13) && !who->get_legend(TASK_2_00,14) ) 
	{
		i = to_int(arg);
		if ( i == 3 )
			send_user( who, "%c%c%w%s", ':',3,npc->get_char_picid(), sprintf("%s\n    尉迟老镖头可是个让劫匪闻风丧胆的人物，年轻时便是一条好汉，他保的镖还从来没丢过，现在年纪大了，便自己开了一家镖局，最近局势不好，听说他生意太好，人手不够，你去看看，能不能帮上忙。记得了，那镖局叫镇威镖局，从这里左边的门出去，穿过中间的天坛，对面就是。\n"ESC"接受任务\ntalk %x# visit.4\n",npc->get_name(),getoid(npc)));	
		else if ( i == 4 )
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_2_00,14);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"周国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,17,"拜访尉迟老镖头" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"拜访尉迟老镖头");
		}
	}

}