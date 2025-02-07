
#include <ansi.h>
#include <city.h>

#define COMRADE_NPC_02          "/npc/war/0002"         // 神机院主
#define COMRADE_NPC_03          "/npc/war/0003"         // 武教头

#define COMRADE_NPC_95          "/npc/war/0095"         // 总管

#define COMRADE_NPC_10          "/npc/war/0010"         // 混混
#define COMRADE_NPC_20          "/npc/war/0020"         // 飞贼
#define COMRADE_NPC_30          "/npc/war/0030"         // 强盗
#define COMRADE_NPC_15          "/npc/war/0015"         // 狂徒
#define COMRADE_NPC_25          "/npc/war/0025"         // 流氓
#define COMRADE_NPC_35          "/npc/war/0035"         // 恶棍

#define COMRADE_TOWER           "/npc/war/0080"         // 箭塔
#define COMRADE_TOWER2           "/npc/war/0085"         // 打手

// 函数：生成二进制码
void SAVE_BINARY() { }

// 函数：五分钟公告(战争准备)
void war_ready_notice( object map )
{
        string name1, name2;

        name1 = map->get_war_attack();
        name2 = map->get_war_defense();

        FAMILY_D->org_channel( name1, 0, sprintf( HIR "帮主已经下达了剿灭“%s”的指令，请帮中所有成员马上作好出战的准备，战争将在%d秒后开始。", name2, map->get_starttime() - time() ) );
        FAMILY_D->org_channel( name2, 0, sprintf( HIR "“%s”向我们发出了挑战，请帮中所有成员马上着手准备应战，战争将在%d秒后开始。。", name1, map->get_starttime() - time() ) );
}

// 函数：倒计时处理(战争开始)
void war_begin_count_down_notice( object map, int sec ) 
{
        object npc, npc2, npc3;
        string name1, name2, *xy;
        int p1, z1, x1, y1;
        int p2, z2, x2, y2;
        int i, size;

        name1 = map->get_war_attack();
        name2 = map->get_war_defense();

        if( sec > 0 )
        {
                FAMILY_D->org_channel( name1, 0, sprintf( HIR "还有%d秒帮派战场开放，请大家作好决战准备。", sec ) );
                FAMILY_D->org_channel( name2, 0, sprintf( HIR "还有%d秒帮派战场开放，请大家作好决战准备", sec ) );
        }
        else
        {
//                log_file("test", sprintf("%s 战争开始\n", short_time()));
                map->cleanup_char_and_item(map);    // 清除人物、物品

                FAMILY_D->org_channel( name1, 0, sprintf( HIR "与%s的战斗已经展开，请大家务必助本帮一臂之力！", name2 ) );
                FAMILY_D->org_channel( name1, 0, sprintf( HIR "请大家尽快加入与%s的决战！", name2 ) );
                FAMILY_D->org_channel( name2, 0, sprintf( HIR "与%s的战斗已经展开，请大家务必助本帮一臂之力！", name1 ) );
                FAMILY_D->org_channel( name2, 0, sprintf( HIR "请大家尽快加入与%s的决战！", name1 ) );

                z1 = map->get_id();

                p1 = QUEST_BATTLE->get_comrade_point(z1, 10);
                map->set_battle_x( 10, p1 / 1000 );
                map->set_battle_y( 10, p1 % 1000 );

                p1 = QUEST_BATTLE->get_comrade_point(z1, 11);
                map->set_battle_x( 11, p1 / 1000 );
                map->set_battle_y( 11, p1 % 1000 );

                p1 = QUEST_BATTLE->get_comrade_point(z1, 12);
                map->set_battle_x( 12, p1 / 1000 );
                map->set_battle_y( 12, p1 % 1000 );

                p1 = QUEST_BATTLE->get_comrade_point(z1, 15);
                map->set_battle_x( 15, p1 / 1000 );
                map->set_battle_y( 15, p1 % 1000 );

                p1 = QUEST_BATTLE->get_comrade_point(z1, 16);
                map->set_battle_x( 16, p1 / 1000 );
                map->set_battle_y( 16, p1 % 1000 );

                p1 = QUEST_BATTLE->get_comrade_point(z1, 17);
                map->set_battle_x( 17, p1 / 1000 );
                map->set_battle_y( 17, p1 % 1000 );

                map->make_virtual_line();    // 生成两条虚线
                map->make_battle_d();    // 生成坐标距离

                if(   ( p1 = QUEST_BATTLE->get_valid_manager_xy(z1, 1) )
                &&    ( p2 = QUEST_BATTLE->get_valid_manager_xy(z1, 2) ) )
                {
                        x1 = ( p1 % 1000000 ) / 1000;
                        y1 = p1 % 1000;

                        z2 = z1;
                        x2 = ( p2 % 1000000 ) / 1000;
                        y2 = p2 % 1000;

                        npc2 = new( COMRADE_NPC_95 );
                        npc2->set_org_name(name1);
                        npc2->set_front(1);
                        npc2->add_to_scene(z1, x1, y1, 8);    // 攻击方总管

                        npc3 = new( COMRADE_NPC_95 );
                        npc3->set_org_name(name2);
                        npc3->set_front(2);
                        npc3->add_to_scene(z2, x2, y2, 4);    // 防守方总管

                        npc2->set_manager(npc2);
                        npc3->set_manager(npc3);

                        map->set_manager(npc2);
                        map->set_manager_2(npc3);

                        if( ( p1 = QUEST_BATTLE->get_valid_manager_xy(z1, 11) ) )
                        {
                                x1 = ( p1 % 1000000 ) / 1000;
                                y1 = p1 % 1000;

                                npc = new( COMRADE_NPC_02 );
                                npc->set_org_name(name1);
                                npc->set_front(1);
                                npc->set_manager(npc2);
                                npc->add_to_scene(z1, x1, y1, 8);    // 攻击方神机院主
                                npc = new( COMRADE_NPC_03 );
                                npc->set_org_name(name1);
                                npc->set_front(1);
                                npc->set_manager(npc2);
                                npc->add_to_scene(z1, x1+2, y1+2, 8);    // 攻击方神机院主
                                
                        }
                        if( ( p2 = QUEST_BATTLE->get_valid_manager_xy(z1, 12) ) )
                        {
                                z2 = z1;
                                x2 = ( p2 % 1000000 ) / 1000;
                                y2 = p2 % 1000;

                                npc = new( COMRADE_NPC_02 );
                                npc->set_org_name(name2);
                                npc->set_front(2);
                                npc->set_manager(npc3);
                                npc->add_to_scene(z2, x2, y2, 8);    // 防守方神机院主
                                npc = new( COMRADE_NPC_03 );
                                npc->set_org_name(name2);
                                npc->set_front(2);
                                npc->set_manager(npc3);
                                npc->add_to_scene(z2, x2+2, y2+2, 8);    // 防守方神机院主
                        }

                        z1 = map->get_id();

                        xy = QUEST_BATTLE->get_tower_array(z1, 0);
                        for( i = 0, size = sizeof(xy); i < size; i ++ )
                        {
                                if( sscanf( xy[i], "%d,%d", x1, y1 ) != 2 ) continue;
                                if( get_block(z1, x1, y1) & IS_CHAR_BLOCK ) continue;

                                npc = new( COMRADE_TOWER2 );
                                npc->set_char_picid(0202);
                                npc->set_level(0);
                                npc->set_org_name(name1);
                                npc->set_front(1);
                                npc->set_manager(npc2);
                                npc->add_to_scene(z1, x1, y1, 8);    // 攻击方箭塔
                                map->add_comrade(npc);
                        }
                        xy = QUEST_BATTLE->get_tower_array(z1, 1);
                        for( i = 0, size = sizeof(xy); i < size; i ++ )
                        {
                                if( sscanf( xy[i], "%d,%d", x1, y1 ) != 2 ) continue;
                                if( get_block(z1, x1, y1) & IS_CHAR_BLOCK ) continue;

                                npc = new( COMRADE_TOWER );
                                npc->set_char_picid(9901);
                                npc->set_level(1);
                                npc->set_org_name(name1);
                                npc->set_front(1);
                                npc->set_manager(npc2);
                                npc->add_to_scene(z1, x1, y1, 8);    // 攻击方箭塔
                                map->add_tower(npc);
                        }
                        xy = QUEST_BATTLE->get_tower_array(z1, 2);
                        for( i = 0, size = sizeof(xy); i < size; i ++ )
                        {
                                if( sscanf( xy[i], "%d,%d", x1, y1 ) != 2 ) continue;
                                if( get_block(z1, x1, y1) & IS_CHAR_BLOCK ) continue;

                                npc = new( COMRADE_TOWER );
                                npc->set_char_picid(9902);
                                npc->set_level(2);
                                npc->set_org_name(name1);
                                npc->set_front(1);
                                npc->set_manager(npc2);
                                npc->add_to_scene(z1, x1, y1, 8);    // 攻击方箭塔
                                map->add_tower(npc);
                        }
                        xy = QUEST_BATTLE->get_tower_array(z1, 3);
                        for( i = 0, size = sizeof(xy); i < size; i ++ )
                        {
                                if( sscanf( xy[i], "%d,%d", x1, y1 ) != 2 ) continue;
                                if( get_block(z1, x1, y1) & IS_CHAR_BLOCK ) continue;

                                npc = new( COMRADE_TOWER );
                                npc->set_char_picid(9903);
                                npc->set_level(3);
                                npc->set_org_name(name1);
                                npc->set_front(1);
                                npc->set_manager(npc2);
                                npc->add_to_scene(z1, x1, y1, 8);    // 攻击方箭塔
                                map->add_tower(npc);
                        }
                        xy = QUEST_BATTLE->get_tower_array(z1, 4);
                        for( i = 0, size = sizeof(xy); i < size; i ++ )
                        {
                                if( sscanf( xy[i], "%d,%d", x1, y1 ) != 2 ) continue;
                                if( get_block(z1, x1, y1) & IS_CHAR_BLOCK ) continue;

                                npc = new( COMRADE_TOWER );
                                npc->set_char_picid(9904);
                                npc->set_level(4);
                                npc->set_org_name(name1);
                                npc->set_front(1);
                                npc->set_manager(npc2);
                                npc->add_to_scene(z1, x1, y1, 8);    // 攻击方箭塔
                                map->add_tower(npc);
                        }

                        xy = QUEST_BATTLE->get_tower_array(z1, 5);
                        for( i = 0, size = sizeof(xy); i < size; i ++ )
                        {
                                if( sscanf( xy[i], "%d,%d", x1, y1 ) != 2 ) continue;
                                if( get_block(z1, x1, y1) & IS_CHAR_BLOCK ) continue;

                                npc = new( COMRADE_TOWER2 );
                                npc->set_char_picid(0053);
                                npc->set_level(0);
                                npc->set_org_name(name2);
                                npc->set_front(2);
                                npc->set_manager(npc3);
                                npc->add_to_scene(z1, x1, y1, 4);    // 防守方箭塔
                                map->add_comrade_2(npc);
                        }
                        xy = QUEST_BATTLE->get_tower_array(z1, 6);
                        for( i = 0, size = sizeof(xy); i < size; i ++ )
                        {
                                if( sscanf( xy[i], "%d,%d", x1, y1 ) != 2 ) continue;
                                if( get_block(z1, x1, y1) & IS_CHAR_BLOCK ) continue;

                                npc = new( COMRADE_TOWER );
                                npc->set_char_picid(9901);
                                npc->set_level(1);
                                npc->set_org_name(name2);
                                npc->set_front(2);
                                npc->set_manager(npc3);
                                npc->add_to_scene(z1, x1, y1, 4);    // 防守方箭塔
                                map->add_tower_2(npc);
                        }
                        xy = QUEST_BATTLE->get_tower_array(z1, 7);
                        for( i = 0, size = sizeof(xy); i < size; i ++ )
                        {
                                if( sscanf( xy[i], "%d,%d", x1, y1 ) != 2 ) continue;
                                if( get_block(z1, x1, y1) & IS_CHAR_BLOCK ) continue;

                                npc = new( COMRADE_TOWER );
                                npc->set_char_picid(9902);
                                npc->set_level(2);
                                npc->set_org_name(name2);
                                npc->set_front(2);
                                npc->set_manager(npc3);
                                npc->add_to_scene(z1, x1, y1, 4);    // 防守方箭塔
                                map->add_tower_2(npc);
                        }
                        xy = QUEST_BATTLE->get_tower_array(z1, 8);
                        for( i = 0, size = sizeof(xy); i < size; i ++ )
                        {
                                if( sscanf( xy[i], "%d,%d", x1, y1 ) != 2 ) continue;
                                if( get_block(z1, x1, y1) & IS_CHAR_BLOCK ) continue;

                                npc = new( COMRADE_TOWER );
                                npc->set_char_picid(9903);
                                npc->set_level(3);
                                npc->set_org_name(name2);
                                npc->set_front(2);
                                npc->set_manager(npc3);
                                npc->add_to_scene(z1, x1, y1, 4);    // 防守方箭塔
                                map->add_tower_2(npc);
                        }
                        xy = QUEST_BATTLE->get_tower_array(z1, 9);
                        for( i = 0, size = sizeof(xy); i < size; i ++ )
                        {
                                if( sscanf( xy[i], "%d,%d", x1, y1 ) != 2 ) continue;
                                if( get_block(z1, x1, y1) & IS_CHAR_BLOCK ) continue;

                                npc = new( COMRADE_TOWER );
                                npc->set_char_picid(9904);
                                npc->set_level(4);
                                npc->set_org_name(name2);
                                npc->set_front(2);
                                npc->set_manager(npc3);
                                npc->add_to_scene(z1, x1, y1, 4);    // 防守方箭塔
                                map->add_tower_2(npc);
                        }
                }

	        map->set_war(WAR_BEGIN);
	        map->set_heart_sec(60);    // 校正时钟    // 80 - 60 = 20 秒后出第一批怪
        }
}

// 函数：三分钟公告(战争开始)
void war_begin_notice( object map )
{
        string name1, name2;

        name1 = map->get_war_attack();
        name2 = map->get_war_defense();	
        FAMILY_D->org_channel( name1, 0, sprintf( HIR "与%s的战斗已经展开，请大家务必助本帮一臂之力！", name2 ) );
        FAMILY_D->org_channel( name1, 0, sprintf( HIR "请大家尽快加入与%s的决战！", name2 ) );
        FAMILY_D->org_channel( name2, 0, sprintf( HIR "与%s的战斗已经展开，请大家务必助本帮一臂之力！", name1 ) );
        FAMILY_D->org_channel( name2, 0, sprintf( HIR "请大家尽快加入与%s的决战！", name1 ) );
}

// 函数：战争中止公告
void war_stop_notice( object map )
{
        string name1, name2;
        name1 = map->get_war_attack();
        name2 = map->get_war_defense();

        FAMILY_D->org_channel( name1, 0, sprintf( HIR "与“%s”的战争中止了，帮中资金减少30万。", name2 ) );
        FAMILY_D->org_channel( name2, 0, sprintf( HIR "“%s”中止了战争，本帮得到30万的补偿。", name1 ) );
}

// 函数：１０分钟公告(战争结束)
void war_end_notice( object map )
{
        string name1, name2;

        name1 = map->get_war_attack();
        name2 = map->get_war_defense();

        FAMILY_D->org_channel( name1, 0, "还有１０分钟战场将会关闭，请双方尽快决出胜负。" );
        FAMILY_D->org_channel( name2, 0, "还有１０分钟战场将会关闭，请双方尽快决出胜负。" );
}

// 函数：５分钟公告(战争结束)
void war_end_notice_2( object map )
{
        string name1, name2;

        name1 = map->get_war_attack();
        name2 = map->get_war_defense();

        FAMILY_D->org_channel( name1, 0, "还有５分钟战场将会关闭，请双方尽快决出胜负。" );
        FAMILY_D->org_channel( name2, 0, "还有５分钟战场将会关闭，请双方尽快决出胜负。" );
}

// 函数：(战争结束)
void war_end( object map ) 
{
        object npc, attack, defence;
        string name1, name2, result;
        int gold, allgold, stable, favour, store, oldgold;

        name1 = map->get_war_attack();
        name2 = map->get_war_defense();
        attack = CITY_ZHOU->get_2( sprintf( "org.%s", name1 ) );
        defence = CITY_ZHOU->get_2( sprintf( "org.%s", name2 ) );

        if(     name1 && name1 != ""
        &&      objectp( npc = CITY_ZHOU->get_2( sprintf( "org.%s", name1 ) ) ) )    // 帮派存在
        {
                npc->set_war(NO_WAR);
        }
        if(     name2 && name2 != ""
        &&      objectp( npc = CITY_ZHOU->get_2( sprintf( "org.%s", name2 ) ) ) )    // 帮派存在
        {
                npc->set_war(NO_WAR);
        }
        if (map->get_winer())
        {
        	
        	allgold = defence->get_gold()/20+30000;
        	oldgold = defence->get_gold();
        	stable = defence->get_stable();
        	favour = defence->get_favour();
        	store = defence->get_store();
        	defence->add_stable(-stable/50-20);
        	defence->add_favour(-favour/50-20);
        	if (allgold>defence->get_gold())
        	{
        		gold = defence->get_gold();
        		defence->set_gold(0);
        		allgold -= gold;
        		if (defence->get_store()*5000>allgold)
        		{
        			defence->add_store(-allgold/5000-1);
        		}
        		else
        		{
        			allgold -= defence->get_store()*5000;
        			defence->set_store(0);
        			if (allgold>0)
        			{
        				if (defence->get_stable()*2000>allgold)
        				{
        					defence->add_stable(-allgold/2000-1);
        				}
        				else
        				{
		        			allgold -= defence->get_stable()*2000;
		        			defence->set_stable(0);  
		        			if (allgold>0) defence->add_favour(-allgold/2000-1);      					
        				}
        			}
        		}
        	}
        	else 
        	{
        		defence->add_gold(-allgold);
        		gold = allgold;
        	}
        	
        	result = sprintf(HIR"因为帮战惨败，本帮一共向%s支付了%d战败赔偿金。帮派人气度下降%d点，安定度下降%d点。", name1, gold, favour - defence->get_favour(), stable - defence->get_stable() );
        	FAMILY_D->org_channel( name2, 0, result);
        	gold = oldgold / 10 + 50000;
        	attack->add_gold(gold);
        	attack->add_stable(300);
        	attack->add_favour(100);
        	result = sprintf(HIR"本次帮战获得了全面的胜利，%s一共向本帮支付了%d战败赔偿金。同时帮派人气度上升%d点，安定度上升%d点。", name2, gold, 100, 300 );
        	FAMILY_D->org_channel( name1, 0, result);
        	result = sprintf(HIR"听说因为帮战惨败，%s向%s赔偿了%d金。", name2, name1, gold );
        	CHAT_D->rumor_player_channel( 0, result);
        }
        else
        {
        	
        	allgold = attack->get_gold()/20+50000;
        	oldgold = attack->get_gold();
        	stable = attack->get_stable();
        	favour = attack->get_favour();
        	store = attack->get_store();     
        	attack->add_stable(-stable/50-30);
        	attack->add_favour(-favour/50-30);        	
        	if (allgold>attack->get_gold())
        	{
        		gold = attack->get_gold();
        		attack->set_gold(0);
        		allgold -= gold;
        		if (attack->get_store()*5000>allgold)
        		{
        			attack->add_store(-allgold/5000-1);
        		}
        		else
        		{
        			allgold -= attack->get_store()*5000;
        			attack->set_store(0);
        			if (allgold>0)
        			{
        				if (attack->get_stable()*2000>allgold)
        				{
        					attack->add_stable(-allgold/2000-1);
        				}
        				else
        				{
		        			allgold -= attack->get_stable()*2000;
		        			attack->set_stable(0);  
		        			if (allgold>0) defence->add_favour(-allgold/2000-1);      					
        				}
        			}
        		}
        	}
        	else 
        	{
        		attack->add_gold(-allgold);
        		gold = allgold;
        	}   
        	
        	result = sprintf(HIR"因为帮战惨败，本帮一共向%s支付了%d战败赔偿金。帮派人气度下降%d点，安定度下降%d点。", name2, gold, favour - attack->get_favour(), stable - attack->get_stable() );     	   	
        	FAMILY_D->org_channel( name1, 0, result);
        	gold = oldgold * 3 / 20 + 50000;
        	defence->add_gold(gold);
        	defence->add_stable(330);
        	defence->add_favour(180);        
        	result = sprintf(HIR"本次帮战获得了全面的胜利，%s一共向本帮支付了%d战败赔偿金。同时帮派人气度上升%d点，安定度上升%d点。", name1, gold, 180, 330 );
        	FAMILY_D->org_channel( name2, 0, result);
        	result = sprintf(HIR"听说因为帮战惨败，%s向%s赔偿了%d金。", name1, name2, gold );
        	CHAT_D->rumor_player_channel( 0, result);        		
        }        
        
//        log_file("test", sprintf("%s 战争结束\n", short_time()));
        map->set_war(NO_WAR);

        BATTLE->destruct_virtual_map( map, map->get_id() );
}

// 函数：倒计时处理(战争结束)
void war_end_count_down_notice( object map, int sec ) 
{
        string name1, name2;

        name1 = map->get_war_attack();
        name2 = map->get_war_defense();

        if( sec > 0 )
        {
                FAMILY_D->org_channel( name1, 0, sprintf( HIR "还有 %d 秒战场将关闭，请双方尽快决出胜负。", sec ) );
                FAMILY_D->org_channel( name2, 0, sprintf( HIR "还有 %d 秒战场将关闭，请双方尽快决出胜负。", sec, name2 ) );
        }
        else
        {
                FAMILY_D->org_channel( name1, 0, sprintf( HIR "战争结束，“%s”获得胜利！", name2 ) );
                FAMILY_D->org_channel( name2, 0, sprintf( HIR "战争结束，“%s”获得胜利！", name2 ) );

                war_end(map);
        }
}

// 函数：放置战争ＮＰＣ(战争之中)
void add_comrade_to_battle( object map, int flag )
{
        object npc, npc2, npc3, orgnpc2, orgnpc3;
        string name1, name2;
        string *comrade_table, *comrade_table_2;
        int p, p2, z, x, y;
        int i, size;

        z = map->get_id();
        name1 = map->get_war_attack();
        name2 = map->get_war_defense();
        orgnpc2 = CITY_ZHOU->get_2( sprintf( "org.%s", name1 ) );
        orgnpc3 = CITY_ZHOU->get_2( sprintf( "org.%s", name2 ) );

        switch( flag )
        {
      default : comrade_table = ({ COMRADE_NPC_10, COMRADE_NPC_10, COMRADE_NPC_10, COMRADE_NPC_20, COMRADE_NPC_30 });
                comrade_table_2 = ({ COMRADE_NPC_15, COMRADE_NPC_15, COMRADE_NPC_15, COMRADE_NPC_25, COMRADE_NPC_35 });
                break;
       case 2 : comrade_table = ({ COMRADE_NPC_20, COMRADE_NPC_20, COMRADE_NPC_20, COMRADE_NPC_30, COMRADE_NPC_30 });
                comrade_table_2 = ({ COMRADE_NPC_25, COMRADE_NPC_25, COMRADE_NPC_25, COMRADE_NPC_35, COMRADE_NPC_35 });
                break;
       case 3 : comrade_table = ({ COMRADE_NPC_10, COMRADE_NPC_10, COMRADE_NPC_10, COMRADE_NPC_20, COMRADE_NPC_30 });
                comrade_table_2 = ({ COMRADE_NPC_15, COMRADE_NPC_15, COMRADE_NPC_15, COMRADE_NPC_25, COMRADE_NPC_35 });
                break;
        }

        npc2 = map->get_manager();
        npc3 = map->get_manager_2();

        for( i = 0, size = sizeof(comrade_table); i < size; i ++ )
        {
                if( map->sizeof_comrade_dbase() >= 100 ) break;
		if (orgnpc2->get_gold()==0) 
		{
			FAMILY_D->org_channel(name1, 0, HIR"帮派资金不足，无法招募帮手协助战争。");
			break;
		}
		orgnpc2->add_gold(-5);
                if( p = get_jumpin(z, 10) )
                {
                        x = p / 1000;  y = p % 1000;

                        npc = new( comrade_table[i] );
                        npc->set_name(name1+npc->get_name());
                        npc->set_org_name(name1);
                        npc->set_front(1);
                        npc->set_manager(npc2);
                        npc->add_to_scene(z, x, y, 3);
                        map->add_comrade(npc);
                }
                if( p = get_jumpin(z, 11) )
                {
                        x = p / 1000;  y = p % 1000;

                        npc = new( comrade_table[i] );
                        npc->set_name(name1+npc->get_name());
                        npc->set_org_name(name1);
                        npc->set_front(1);
                        npc->set_manager(npc2);
                        npc->add_to_scene(z, x, y, 3);
                        map->add_comrade(npc);
                }
                if( p = get_jumpin(z, 12) )
                {
                        x = p / 1000;  y = p % 1000;

                        npc = new( comrade_table[i] );
                        npc->set_name(name1+npc->get_name());
                        npc->set_org_name(name1);
                        npc->set_front(1);
                        npc->set_manager(npc2);
                        npc->add_to_scene(z, x, y, 3);
                        map->add_comrade(npc);
                }
        }

        for( i = 0, size = sizeof(comrade_table_2); i < size; i ++ )
        {
                if( map->sizeof_comrade_2_dbase() >= 100 ) break;
		if (orgnpc3->get_gold()==0) 
		{
			FAMILY_D->org_channel(name2, 0, HIR"帮派资金不足，无法招募帮手协助战争。");
			break;
		}
		orgnpc3->add_gold(-5);
                if( p = get_jumpin(z, 15) )
                {
                        x = p / 1000;  y = p % 1000;

                        npc = new( comrade_table_2[i] );
                        npc->set_name(name2+npc->get_name());
                        npc->set_org_name(name2);
                        npc->set_front(2);
                        npc->set_manager(npc3);
                        npc->add_to_scene(z, x, y, 3);
                        map->add_comrade_2(npc);
                }
                if( p = get_jumpin(z, 16) )
                {
                        x = p / 1000;  y = p % 1000;

                        npc = new( comrade_table_2[i] );
                        npc->set_name(name2+npc->get_name());
                        npc->set_org_name(name2);
                        npc->set_front(2);
                        npc->set_manager(npc3);
                        npc->add_to_scene(z, x, y, 3);
                        map->add_comrade_2(npc);
                }
                if( p = get_jumpin(z, 17) )
                {
                        x = p / 1000;  y = p % 1000;

                        npc = new( comrade_table_2[i] );
                        npc->set_name(name2+npc->get_name());
                        npc->set_org_name(name2);
                        npc->set_front(2);
                        npc->set_manager(npc3);
                        npc->add_to_scene(z, x, y, 3);
                        map->add_comrade_2(npc);
                }
        }
}

// 函数：总管死亡奖励
void manager_win_bonus( object me, object who )
{
        object map, orgnpc;
        string name1, name2, name, result;
        int number;
	string leader;
	object *team;
	int size, i, level2, exp2, level, exp;        
	if (who->is_npc())
	{
		if (who->is_comrade())
		{
			who = who->get_manager();
		}
		else
			who = who->get_owner();
	}        
        name = who->get_org_name();
        if (name!="")
        {
		orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );	
		if (objectp(orgnpc))
		{
			number = who->get_number();
			orgnpc->set_member_contribute(number, orgnpc->get_member_contribute(number)+30);
			result = sprintf("你消灭了%s，得到了%d点帮派贡献。", me->get_name(), 30);
			tell_user( who, ECHO + result );
		}	
	}
        if( objectp( map = get_map_object( get_z(me) ) ) )    // 获取战场对象
        {
                name1 = map->get_war_attack();
                name2 = map->get_war_defense();

                if( me->get_org_name() == name1 )    // 攻击方总管
                {
                        FAMILY_D->org_channel( name1, 0, sprintf( HIR "杀死攻方总管，“%s”获得胜利！", name2 ) );
                        FAMILY_D->org_channel( name2, 0, sprintf( HIR "杀死攻方总管，“%s”获得胜利！", name2 ) );
                }
                else if( me->get_org_name() == name2 )    // 防守方总管
                {
                        FAMILY_D->org_channel( name1, 0, sprintf( HIR "杀死守方总管，“%s”获得胜利！", name1 ) );
                        FAMILY_D->org_channel( name2, 0, sprintf( HIR "杀死守方总管，“%s”获得胜利！", name1 ) );
                        map->set_winer(1);
                }

                map->set_war(WAR_END);
                map->set_heart_sec(0);    // 校正时钟
        }
        if( (leader=who->get_leader()) && arrayp( team = who->get_team() ) && sizeof(team) > 1 )
        {
                team = me->correct_bonus_team(team);
                size = sizeof(team);
        }
        else    size = 1;
        exp = 8000;
         
        if( size > 1 )    // 多人
        {
                for( i = 0; i < size; i ++ ) if( team[i] )
                {
                        level2 = level - team[i]->get_level();
                        exp2 = exp*(10+size-1)/10;
                        if (exp2<1) exp2 = 1;
                        exp2 = exp2 * team[i]->get_online_rate()/100;
                        team[i]->add_exp(exp2);
			NPC_SLAVE_D->add_slave_exp(team[i], exp2);
			NPC_PET_D->fight_bonus(team[i],me,size,0,0);
                        team[i]->add_log("&battle", exp2);
			team[i]->add_log("#battle", 1);                        	
                }
        }
        else    // 单人
        {
                level2 = level - who->get_level();
                exp2 = exp;
                exp2 = exp2 * who->get_online_rate()/100;
                who->add_exp(exp2);
                NPC_SLAVE_D->add_slave_exp(who, exp2);
		NPC_PET_D->fight_bonus(who,me,1,0,0);

                who->add_log("&battle", exp2);                
                who->add_log("#battle", 1);
        }
        
}

// 函数：箭塔死亡奖励
void tower_win_bonus( object me, object who )
{
        object map, *char, npc;
        int id, i, size;

        if( objectp( map = get_map_object( get_z(me) ) ) )    // 获取战场对象
        {
                npc = me->get_manager();
                id = getoid(me);

                if( map->get_manager() == npc )    // 攻击方
                {
                        char = map->get_user_dbase();
                        for( i = 0, size = sizeof(char); i < size; i ++ ) 
                                if( objectp( npc = char[i] ) ) send_user( npc, "%c%c%d%w%w", 0x54, 21, id, -1, -1 );
                }
                else if( map->get_manager_2() == npc )    // 防守方
                {
                        char = map->get_user_2_dbase();
                        for( i = 0, size = sizeof(char); i < size; i ++ ) 
                                if( objectp( npc = char[i] ) ) send_user( npc, "%c%c%d%w%w", 0x54, 21, id, -1, -1 );
                }
        }
}

// 函数：NPC 死亡奖励
void comrade_win_bonus( object me, object who )
{
        object map, *char, npc;
        int id, i, size;

        if( objectp( map = get_map_object( get_z(me) ) ) )    // 获取战场对象
        {
                npc = me->get_manager();
                id = getoid(me);

                if( map->get_manager() == npc )    // 攻击方
                {
                        char = map->get_user_dbase();
                        for( i = 0, size = sizeof(char); i < size; i ++ ) 
                                if( objectp( npc = char[i] ) ) send_user( npc, "%c%c%d%w%w", 0x54, 22, id, -1, -1 );
                }
                else if( map->get_manager_2() == npc )    // 防守方
                {
                        char = map->get_user_2_dbase();
                        for( i = 0, size = sizeof(char); i < size; i ++ ) 
                                if( objectp( npc = char[i] ) ) send_user( npc, "%c%c%d%w%w", 0x54, 22, id, -1, -1 );
                }
        }
}
