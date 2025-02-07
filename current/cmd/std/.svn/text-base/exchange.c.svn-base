
#include <ansi.h>
#include <equip.h>
#include <music.h>
#include <public.h>
//exchange + 800 0#0 0#0 0#0 0#0 0#0 0#0 $0 0# 0# 0#
#define EXCHANGENUM 16
// 函数：命令处理
int main( object me, string arg )
{
        object who, *obj, *obj2, obj3, exchangeobj;
        string id, items, *result, legend, name, name2;
        int *item, *item2, *index, *index2, *photo, *flag, gold, gold2;
        int amount, i, size, size2;
	int *pet,*pet2;
	object *oPet,*oPet2;
	int bag, b, c, d, allcount;
	
	string cPet;
	int count,count2;
	if (is_gm(me)) return 1;
        if( !arg )
        {
                notify( "您打算与哪位玩家交易？" );
                return 1;
        }
        else
        if (arg=="cancel")
        {
        	me->set("exchange_time", 0);
        	send_user( me, "%c%c%c", 0x59, 2, 0);
        	return 1;        	
        }
        else if( sscanf( arg, "= %s", id ) )    // 确认对方物品
        {
                if( !( who = find_player(id) ) )
                {
//                      notify( "您找不到这位玩家。" );
                        return 1;
                }
                if( me == who ) 
                {
                        notify( "您不能同自己交易。" );
                        return 1;
                }
                if( who->get_login_flag() < 3 )
                {
                        notify( "对方还没有准备就绪呢。" );
                        return 1;
                }
                if( who->is_die() ) return 1;                
                if( who->get_no_trade() )
                {
                        notify( "对方没有打开交易开关" );
                        return 1;
                }
                if( distance_between(me, who) > 3 )
                {
                        notify( "您距离%s太远了。", who->get_name() );
                        return 1;
                }
                // -------------------------------------------------------------

                if( !who->get_2( "exchange.flag" ) || who->get_2( "exchange.name" ) != me->get_number() ) 
                {
                        notify( "对方不想与您交易东西。" );
                        return 1;
                }
                if( !me->get_2( "exchange.flag" ) || me->get_2( "exchange.name" ) != who->get_number() ) 
                {
                        notify( "您想与谁交易东西？" );
                        return 1;
                }

                if( !stringp(who->get_2( "exchange.mine" )) )
		{
                        notify( "请等待对方确认。" );
                        return 1;
                }
                if( !me->get_2( "exchange.ok" ) )
                {
                        who->set_2( "exchange.ok", 1 );
                        send_user( me, "%c%c", 0x26, 5 );    // 确认对方物品
                        return 1;
                }

                // -------------------------------------------------------------
                
                obj = ({ 0, 0, 0, 0, 0, 0 });  obj2 = ({ 0, 0, 0, 0, 0, 0 });
                item = ({ 0, 0, 0, 0, 0, 0 });  item2 = ({ 0, 0, 0, 0, 0, 0 });  result = ({ "", "" });
                index = ({ 0, 0, 0, 0, 0, 0 });  index2 = ({ 0, 0, 0, 0, 0, 0 });
                pet = ({ 0, 0, 0, });  pet2 = ({ 0, 0, 0, });
                oPet = ({ 0, 0, 0, });  oPet2 = ({ 0, 0, 0, });
                size = 0;  size2 = 0; count = 0; count2 = 0;

                items = me->get_2( "exchange.mine" );
                if( !stringp(items) || sscanf( items, "%x#%d %x#%d %x#%d %x#%d %x#%d %x#%d $%d %x# %x# %x#", 
                        item[0], index[0], item[1], index[1], item[2], index[2], item[3], index[3], item[4], index[4], item[5], index[5], gold, pet[0], pet[1], pet[2] ) != EXCHANGENUM )
                {
                        notify( "您想交易什么东西？" );
                        return 1;
                }
                for( i = 0; i < 6; i ++ ) if( index[i] > 0 )
                {
                        if( !objectp( obj[i] = present( sprintf("%x#", item[i]), me, 1, MAX_CARRY*4 ) ) )
                        {
                                notify( "您找不到第 %d 样东西。", i + 1 );
                                return 1;
                        }
                        if( obj[i]->get_no_drop() || obj[i]->get_no_give() )
                        {
                                notify( obj[i]->get_name() + "不能交易。" );
                                return 1;
                        }
                        if( obj[i]->get_bind()==2 || obj[i]->get_bind()==4 || obj[i]->get_bind()==3 )
                        {
                                notify( obj[i]->get_name() + "不能交易。" );
                                return 1;
                        }                        
                        if( obj[i]->is_locked()>0 )
                        {
                                notify( sprintf("%s离乾坤锁失效还剩余%d小时。", obj[i]->get_name(), obj[i]->is_locked()/3600) );
                                return 1;
                        }
                        if( me->get_store( sprintf( "%02d", get_d( obj[i] ) ) ) )
                        {
                                notify( obj[i]->get_name() + "已经上架，不能交易。" );
                                return 1;
                        }

                        amount = obj[i]->get_amount();
                        if( ( !amount && index[i] != 1 ) || ( amount && ( index[i] < 1 || index[i] > amount ) ) )
                        {
                                notify( "您想交易的 %s 数量不对。", obj[i]->get_name() );
                                return 1;
                        }

                        if( !amount || amount == index[i] ) size --;
                        size2 ++;
                }
                else
                {
                        item[i] = 0;  index[i] = 0;
                }

                if( gold < 0 || gold > me->get_cash() )
                {
                        notify( "您想交易的金钱数量不对。" );
                        return 1;
                }
                if( gold + who->get_cash() > who->get_max_cash() )
                {
                        notify( "对方的现金已达上限。" );    // 您想交易的金额太大。
                        return 1;
                }
		for(i=0;i<3;i++)
		{	
			
			//还要检查能否携带
			if ( (obj3=find_char(sprintf("%x#",pet[i]))) && obj3->is_pet() && obj3->get_owner() == me )
			{
				if ( obj3->get("store") )
				{
		                        notify( obj3->get_name()+"已经摆摊上架，不能交易。" );    
		                        return 1;
		                }
		                if ( obj3->get_save("no_give") ||  obj3->get_save("no_sell") )
				{
		                        notify( obj3->get_name()+"不能交易。" );    
		                        return 1;
		                }
		                if ( obj3->get_save("locktime")>time() )
				{
		                        notify( obj3->get_name()+"已锁定不能交易。" );    
		                        return 1;
		                }		                
				if ( NPC_PET_D->can_carry(who,obj3) !=1 )
				{
					notify( "对方不能携带"+obj3->get_name() );
					return 1;	
				}
				count--;count2++;	
				oPet[i] = obj3;
			}
			else
				pet[i] = 0;
		}
		
                items = who->get_2( "exchange.mine" );
                if( !stringp(items) || sscanf( items, "%x#%d %x#%d %x#%d %x#%d %x#%d %x#%d $%d %x# %x# %x#", 
                        item2[0], index2[0], item2[1], index2[1], item2[2], index2[2], item2[3], index2[3], item2[4], index2[4], item2[5], index2[5], gold2, pet2[0], pet2[1], pet2[2] ) != EXCHANGENUM )
                {
                        send_user( who, "%c%s", '!', "您想交易什么东西？" );
                        return 1;
                }

                for( i = 0; i < 6; i ++ ) if( index2[i] > 0 )
                {
                        if( !objectp( obj2[i] = present( sprintf("%x#", item2[i]), who, 1, MAX_CARRY*4 ) ) )
                        {
                                send_user( who, "%c%s", '!', sprintf( "您找不到第 %d 样东西。", i + 1 ) );
                                return 1;
                        }
                        if( obj2[i]->get_no_drop() || obj2[i]->get_no_give() )
                        {
                                send_user( who, "%c%s", '!', obj2[i]->get_name() + "不能交易。" );
                                return 1;
                        }
                        if( obj2[i]->get_bind()==2 || obj2[i]->get_bind()==4 || obj2[i]->get_bind()==3 )
                        {
                                notify( obj2[i]->get_name() + "不能交易。" );
                                return 1;
                        }                         
                        if( obj2[i]->is_locked()>0 )
                        {
                                send_user( who, "%c%s", '!', sprintf("%s离乾坤锁失效还剩余%d小时。", obj2[i]->get_name(), obj2[i]->is_locked()/3600) );
                                return 1;
                        }
                        if( who->get_store( sprintf( "%02d", get_d( obj2[i] ) ) ) )
                        {
                                send_user( who, "%c%s", '!', obj2[i]->get_name() + "已经上架，不能交易。" );
                                return 1;
                        }

                        amount = obj2[i]->get_amount();
                        if( ( !amount && index2[i] != 1 ) || ( amount && ( index2[i] < 1 || index2[i] > amount ) ) )
                        {
                                send_user( who, "%c%s", '!', sprintf( "您想交易的 %s 数量不对。", obj2[i]->get_name() ) );
                                return 1;
                        }

                        size ++;
                        if( !amount || amount == index2[i] ) size2 --;
                }
                else
                {
                        item2[i] = 0;  index2[i] = 0;
                }

		for(i=0;i<3;i++)
		{
			if ( (obj3=find_char(sprintf("%x#",pet2[i]))) && obj3->is_pet() && obj3->get_owner() == who )
			{
				if ( obj3->get("store") )
				{
					send_user( who, "%c%s", '!', obj3->get_name()+"已经摆摊上架，不能交易。"  );
		                        return 1;
		                }
		                if ( obj3->get_save("no_give") ||  obj3->get_save("no_sell") )
				{
					send_user( who, "%c%s", '!', obj3->get_name()+"不能交易。"  );
		                        return 1;
		                }
		                if ( obj3->get_save("locktime") > time() )
				{
					send_user( who, "%c%s", '!', obj3->get_name()+"已锁定不能交易。"  );
		                        return 1;
		                }		                
				if ( NPC_PET_D->can_carry(me,obj3) !=1 )
				{
					send_user( who, "%c%s", '!', "对方不能携带"+obj3->get_name() );
					return 1;	
				}
				count2--;count++;	
				oPet2[i] = obj3;
			}
			else
				pet2[i] = 0;
		}
		if ( me->get_beast_amount() + count > me->get_beast_max_amount() )
		{
                        send_user( who, "%c%s", '!', me->get_name() + "不能携带更多的宠物。" );
                        send_user( me, "%c%s", '!', "你不能携带更多的宠物。" );
                        return 1;
                }
                if ( who->get_beast_amount() + count2 > who->get_beast_max_amount() )
		{
                        send_user( me, "%c%s", '!', who->get_name() + "不能携带更多的宠物。" );
                        send_user( who, "%c%s", '!', "你不能携带更多的宠物。" );
                        return 1;
                }	
		bag = me->have_bag();
	        b = bag % 100;
	        c = (bag / 100)%100;
	        d = bag / 10000;
		if (b>0 && me->get_bag1_time()>0 && time()>me->get_bag1_time()) b = 0;
		if (c>0 && me->get_bag2_time()>0 && time()>me->get_bag2_time()) c = 0;
		if (d>0 && me->get_bag3_time()>0 && time()>me->get_bag3_time()) d = 0;
	        if( me->get_reincarnation() ) b = MAX_CARRY;    
	        allcount = MAX_CARRY + b + c + d;      
                if( sizeof_inventory(me, 1, MAX_CARRY*4) + size > allcount )
                {
                        send_user( who, "%c%s", '!', me->get_name() + "身上的东西太多了。" );
                        return 1;
                }
		bag = who->have_bag();
	        b = bag % 100;
	        c = (bag / 100)%100;
	        d = bag / 10000;
		if (b>0 && who->get_bag1_time()>0 && time()>who->get_bag1_time()) b = 0;
		if (c>0 && who->get_bag2_time()>0 && time()>who->get_bag2_time()) c = 0;
		if (d>0 && who->get_bag3_time()>0 && time()>who->get_bag3_time()) d = 0;
	        if( who->get_reincarnation() ) b = MAX_CARRY;    
	        allcount = MAX_CARRY + b + c + d;   
                if( sizeof_inventory(who, 1, MAX_CARRY*4) + size2 > allcount )
                {
                	send_user( me, "%c%s", '!', who->get_name() + "身上的东西太多了。" );
                        return 1;
                }

                if( gold2 < 0 || gold2 > who->get_cash() )
                {
                        send_user( who, "%c%s", '!', "您想交易的金钱数量不对。" );
                        return 1;
                }
                if( gold2 + me->get_cash() > me->get_max_cash() )
                {
                        send_user( who, "%c%s", '!', "对方的现金已达上限。" );    // 您想交易的金额太大。
                        return 1;
                }

                // -------------------------------------------------------------

                me->add_cash2(gold2 - gold);  me->add_gold_log("exchange", gold);  me->add_gold_log("exchange2", gold2);
//                me->log_money("交易 "+who->get_id(), gold2 - gold);
                who->add_cash2(gold - gold2);  who->add_gold_log("exchange", gold2);  who->add_gold_log("exchange2", gold);
//		who->log_money("交易 "+me->get_id(), gold - gold2);
		if (gold-gold2>0)
		{
			legend = sprintf("交易给 %s,%d,%s,%s %s,%d,%s,%s 金 0 %d 0 %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), gold-gold2, get_z(me), get_x(me), get_y(me) );
        		"/sys/user/cmd"->log_item(legend);
		}
		else
		if (gold2-gold>0)
		{
			legend = sprintf("交易给 %s,%d,%s,%s %s,%d,%s,%s 金 0 %d 0 %d_%d_%d", who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), gold2-gold, get_z(me), get_x(me), get_y(me) );
        		"/sys/user/cmd"->log_item(legend);			
		}
                if( gold ) result[0] = sprintf( " %d 金", gold );
                if( gold2 ) result[1] = sprintf( " %d 金", gold2 );
                exchangeobj = this_object();
                for( i = 0; i < 6; i ++ ) 
                {
                        if( index[i] > 0 && obj[i] )
                        {
                                if( amount = obj[i]->get_amount() )
                                        items = sprintf( " %s", obj[i]->get_name() );
                                else    items = sprintf( "%s", obj[i]->get_name() );

                                if( result[0] == "" ) result[0] = items;
                                else result[0] = sprintf( "%s、%s", result[0], items );

                                if( !amount || ( amount && index[i] == amount ) )
                                {
                                        obj[i]->remove_from_user();
                                        obj[i]->move(exchangeobj, -1);                                        
                                }
                                else 
                                {
                                        obj[i]->add_amount( - index[i] );
                                        obj3 = obj[i];
                                        obj[i] = new( get_file_name( obj[i] ) );
                                        obj[i]->set_user_id(obj3->get_user_id());
	                                if ( obj3->get("special") )
	                                	obj[i]->set("special",obj3->get("special"));
                                        obj[i]->set_amount( index[i] );
                                }
                        }
                        if( index2[i] > 0 && obj2[i] )
                        {
                                if( amount = obj2[i]->get_amount() )
                                        items = sprintf( " %s", obj2[i]->get_name() );
                                else    items = sprintf( "%s", obj2[i]->get_name() );

                                if( result[1] == "" ) result[1] = items;
                                else result[1] = sprintf( "%s、%s", result[1], items );

                                if( !amount || ( amount && index2[i] == amount ) )
                                {
                                        obj2[i]->remove_from_user();
                                        obj2[i]->move(exchangeobj, -1);
                                }
                                else 
                                {
                                        obj2[i]->add_amount( - index2[i] );
                                        obj3 = obj2[i];
                                        obj2[i] = new( get_file_name( obj2[i] ) );
                                        obj2[i]->set_user_id(obj3->get_user_id());
	                                if ( obj3->get("special") )
	                                	obj2[i]->set("special",obj3->get("special"));
                                        obj2[i]->set_amount( index2[i] );
                                }
                        }                	
                }

                for( i = 0; i < 6; i ++ ) 
                {
                        if( index[i] > 0 && obj[i] )
                        {
				if (obj[i]->is_record())
				{
					legend = sprintf("交易给 %s,%d,%s,%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), obj[i]->get_name(), "/sys/item/item"->get_pawn_save_string(obj[i]), index[i], obj[i]->get_user_id(), get_z(me), get_x(me), get_y(me) );
					"/sys/user/cmd"->log_item(legend);
				}                        	
                                index[i] = obj[i]->move2(who);
                                obj[i]->add_to_user( index[i] );
                        }
                        if( index2[i] > 0 && obj2[i] )
                        {
				if (obj2[i]->is_record())
				{
					legend = sprintf("交易给 %s,%d,%s,%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), obj2[i]->get_name(), "/sys/item/item"->get_pawn_save_string(obj2[i]), index2[i], obj2[i]->get_user_id(), get_z(who), get_x(who), get_y(who) );
					"/sys/user/cmd"->log_item(legend);					
				}                         	
                                index2[i] = obj2[i]->move2(me);
                                obj2[i]->add_to_user( index2[i] );
                        }                	
                }    
                //先从旧主人拿走    
                for(i=0;i<3;i++)
                {
                	if ( pet[i] && oPet[i] )
                	{
                		USER_BEAST_D->remove_from_user(me,oPet[i]);
                		oPet[i]->set_owner(0);
                		if( result[0] == "" ) result[0] = oPet[i]->get_firstname();
                                else result[0] = sprintf( "%s、%s", result[0], oPet[i]->get_firstname() );
                	}
                	if ( pet2[i] && oPet2[i] )
                	{
                		USER_BEAST_D->remove_from_user(who,oPet2[i]);
                		oPet2[i]->set_owner(0);
                		if( result[1] == "" ) result[1] = oPet2[i]->get_firstname();
                                else result[1] = sprintf( "%s、%s", result[1], oPet2[i]->get_firstname() );
                	}
                }
                //给新主人
                for(i=0;i<3;i++)
                {
                	if ( pet[i] && oPet[i] )
                	{
                		oPet[i]->set_owner(who);
                		oPet[i]->add_faith(-20);
                		who->add_beast(oPet[i]);
                		oPet[i]->send_info();
                	}
                	if ( pet2[i] && oPet2[i] )
                	{
                		oPet2[i]->set_owner(me);
                		oPet2[i]->add_faith(-20);
                		me->add_beast(oPet2[i]);
                		oPet2[i]->send_info();
                	}	
                }        
                me->to_front_eachother(who);

                send_user( me, "%c%w", 0x0d, MUSIC_EXCHANGE );
                send_user( who, "%c%w", 0x0d, MUSIC_EXCHANGE );

                if( result[0] != "" )
                        printf( ECHO "你拿出%s同%s(%d)交易%s。", result[0], who->get_name(), who->get_number(), result[1] );
                else    printf( ECHO "%s(%d)拿出%s同你交易。", who->get_name(), who->get_number(), result[1] );
                if( result[1] != "" )
                        write_user( who, ECHO "你拿出%s同%s(%d)交易%s。", result[1], me->get_name(), me->get_number(), result[0] );
                else    write_user( who, ECHO "%s(%d)拿出%s同你交易。", me->get_name(), me->get_number(), result[0] );

                me->delete_2("exchange");
                who->delete_2("exchange");
                send_user( me, "%c%c", 0x26, 0 );    // 关闭交易窗口
                send_user( who, "%c%c", 0x26, 0 );    // 关闭交易窗口
		//宠物存盘
		for(i=0;i<3;i++)
                {
                	if ( pet[i] && oPet[i] )
                		oPet[i]->save();
                	if ( pet2[i] && oPet2[i] )
                		oPet2[i]->save();	
                }

                return 1;
        }
        else if( sscanf( arg, "# %s", id ) )    // 取消对方确认（更改自己物品）
        {
                if( !( who = find_player(id) ) )
                {
//                      notify( "您找不到这位玩家。" );
                        return 1;
                }
                if( me == who ) 
                {
                        notify( "您不能与自己交易东西。" );
                        return 1;
                }
                if( who->get_login_flag() < 3 )
                {
                        notify( "对方还没有准备就绪呢。" );
                        return 1;
                }
                if( who->is_die() ) return 1;

                if( !who->get_2( "exchange.flag" ) || who->get_2( "exchange.name" ) != me->get_number() ) 
                {
                        notify( "对方不想与您交易东西。" );
                        return 1;
                }
                if( !me->get_2( "exchange.flag" ) || me->get_2( "exchange.name" ) != who->get_number() ) 
                {
                        notify( "您想与谁交易东西？" );
                        return 1;
                }

                me->set_2( "exchange.ok", 0 );
                me->set_2( "exchange.mine", 0 );
                send_user( who, "%c%c", 0x26, 3 );    // 取消对方确认（更改自己物品）

                return 1;
        }
        else if( sscanf( arg, "+ %s %s", id, items ) )    // 确认己方物品
        {
                if( !( who = find_player(id) ) )
                {
//                      notify( "您找不到这位玩家。" );
                        send_user( me, "%c%c", 0x26, 4 );    // 己方物品错误
                        return 1;
                }
                if( me == who ) 
                {
                        notify( "您不能同自己交易。" );
                        send_user( me, "%c%c", 0x26, 4 );    // 己方物品错误
                        return 1;
                }
                if( who->get_login_flag() < 3 )
                {
                        notify( "对方还没有准备就绪呢。" );
                        return 1;
                }
                if( who->is_die() ) return 1;

                if( !who->get_2( "exchange.flag" ) || who->get_2( "exchange.name" ) != me->get_number() ) 
                {
                        notify( "对方不想与您交易东西。" );
                        send_user( me, "%c%c", 0x26, 4 );    // 己方物品错误
                        return 1;
                }
                if( !me->get_2( "exchange.flag" ) || me->get_2( "exchange.name" ) != who->get_number() ) 
                {
                        notify( "您想与谁交易东西？" );
                        send_user( me, "%c%c", 0x26, 4 );    // 己方物品错误
                        return 1;
                }

                if( distance_between(me, who) > 3 )
                {
                        notify( "您距离%s太远了。", who->get_name() );
                        send_user( me, "%c%c", 0x26, 4 );    // 己方物品错误
                        return 1;
                }

                // -------------------------------------------------------------

                obj = ({ 0, 0, 0, 0, 0, 0 });  item = ({ 0, 0, 0, 0, 0, 0 });  
                index = ({ 0, 0, 0, 0, 0, 0 });  photo = ({ 0, 0, 0, 0, 0, 0 });  flag = ({ 0, 0, 0, 0, 0, 0 });
		pet = ({0,0,0});
                if( sscanf( items, "%x#%d %x#%d %x#%d %x#%d %x#%d %x#%d $%d %x# %x# %x#", 
                        item[0], index[0], item[1], index[1], item[2], index[2], item[3], index[3], item[4], index[4], item[5], index[5], gold,pet[0],pet[1],pet[2] ) != EXCHANGENUM )
                {
                        notify( "您想交易什么东西？" );
                        send_user( me, "%c%c", 0x26, 4 );    // 己方物品错误
                        return 1;
                }

                for( i = 0; i < 6; i ++ ) if( index[i] > 0 )
                {
                        if( !objectp( obj[i] = present( sprintf("%x#", item[i]), me, 1, MAX_CARRY*4 ) ) )
                        {
                                notify( "您找不到第 %d 样东西。", i + 1 );
                                send_user( me, "%c%c", 0x26, 4 );    // 己方物品错误
                                return 1;
                        }
                        if( obj[i]->get_no_drop() || obj[i]->get_no_give() )
                        {
                                notify( obj[i]->get_name() + "不能交易。" );
                                send_user( me, "%c%c", 0x26, 4 );    // 己方物品错误
                                return 1;
                        }
                        if( obj[i]->get_bind()==2 || obj[i]->get_bind()==4 || obj[i]->get_bind()==3 )
                        {
                                notify( obj[i]->get_name() + "不能交易。" );
                                return 1;
                        }                         
                        if( obj[i]->is_locked()>0 )
                        {
                                notify( sprintf("%s离乾坤锁失效还剩余%d小时。", obj[i]->get_name(), obj[i]->is_locked()/3600) );
                                send_user( me, "%c%c", 0x26, 4 );    // 己方物品错误
                                return 1;
                        }
                        if( me->get_store( sprintf( "%02d", get_d( obj[i] ) ) ) )
                        {
                                notify( obj[i]->get_name() + "已经上架，不能交易。" );
                                send_user( me, "%c%c", 0x26, 4 );    // 己方物品错误
                                return 1;
                        }

                        amount = obj[i]->get_amount();
                        if( ( !amount && index[i] != 1 ) || ( amount && ( index[i] < 1 || index[i] > amount ) ) )
                        {
                                notify( "您想交易的 %s 数量不对。", obj[i]->get_name() );
                                send_user( me, "%c%c", 0x26, 4 );    // 己方物品错误
                                return 1;
                        }

                        photo[i] = obj[i]->get_picid_2();
                        flag[i] = 0;
                }
                else
                {
                        item[i] = 0;  index[i] = 0;
                }

                if( gold < 0 || gold > me->get_cash() )
                {
                        notify( "您想交易的金钱数量不对。" );
                        send_user( me, "%c%c", 0x26, 4 );    // 己方物品错误
                        return 1;
                }
                if( gold + who->get_cash() > who->get_max_cash() )
                {
                        notify( "对方的现金已达上限。" );    // 您想交易的金额太大。
                        send_user( me, "%c%c", 0x26, 4 );    // 己方物品错误
                        return 1;
                }
		//宠物
		cPet = "";
		for(i=0;i<3;i++)
		{
			if ( (obj3=find_char(sprintf("%x#",pet[i]))) && obj3->is_pet() && obj3->get_owner() == me )
			{
				if ( obj3->get("store") )
				{
		                        notify( obj3->get_name()+"已经摆摊上架，不能交易。" );    
		                        send_user( me, "%c%c", 0x26, 4 );    // 己方物品错误
		                        return 1;
		                }
		                if ( obj3->get_save("no_give") ||  obj3->get_save("no_sell") )
				{
		                        notify( obj3->get_name()+"不能交易。" );    
		                        send_user( me, "%c%c", 0x26, 4 );    // 己方物品错误
		                        return 1;
		                }
				cPet += sprintf("|%d|%s",pet[i],obj3->get_firstname());
			}
		}
		
                me->set_2( "exchange.mine", items );
                me->set_2( "exchange.ok", 0 );

                send_user( who, "%c%c%d%w%w%c%d%w%w%c%d%w%w%c%d%w%w%c%d%w%w%c%d%w%w%c%d%s", 0x26, 7, 
                        item[0], photo[0], index[0], flag[0], item[1], photo[1], index[1], flag[1],
                        item[2], photo[2], index[2], flag[2], item[3], photo[3], index[3], flag[3],
                        item[4], photo[4], index[4], flag[4], item[5], photo[5], index[5], flag[5], gold, cPet );

                return 1;
        }
        else if( sscanf( arg, "? %s %x", id, i ) )    // 查询物品描述
        {
                if( !( who = find_player(id) ) )
                {
//                      notify( "您找不到这位玩家。" );
                        return 1;
                }

                if( !who->get_2( "exchange.flag" ) || who->get_2( "exchange.name" ) != me->get_number() ) 
                {
                        notify( "对方不想与您交易东西。" );
                        return 1;
                }
                if( !me->get_2( "exchange.flag" ) || me->get_2( "exchange.name" ) != who->get_number() ) 
                {
                        notify( "您想与谁交易东西？" );
                        return 1;
                }

                if( objectp( obj3 = present( sprintf("%x#", i), who, 1, MAX_CARRY*4 ) ) )
                        send_user( me, "%c%c%d%s", 0x26, 6, i, ITEM_ITEM_D->get_look_string(me, obj3) );

                return 1;
        }
        else if( sscanf( arg, "? %x", i ) )    // 查询物品描述
        {
                if( objectp( obj3 = present( sprintf("%x#", i), me, 1, MAX_CARRY*4 ) ) )
                        send_user( me, "%c%c%d%s", 0x26, 6, i, ITEM_ITEM_D->get_look_string(me, obj3) );

                return 1;
        }
	else if( sscanf( arg, "?? %s", id ) )    // 查询物品描述
        {
                if( objectp( obj3 = find_char(id) ) && obj3->is_pet() )
		{
			obj3->send_info_to(me);	
		}
                return 1;
        }
        else if( sscanf( arg, "- %s", id ) )    // 关闭交易窗口
        {
                me->delete_2("exchange");
                send_user( me, "%c%c", 0x26, 0 );    // 关闭交易窗口

                if( !( who = find_player(id) ) )
                {
//                      notify( "您找不到这位玩家。" );
                        return 1;
                }
                if( !who->get_2( "exchange.flag" ) || who->get_2( "exchange.name" ) != me->get_number() ) 
                {
                        notify( "对方与您没有交易关系。" );
                        return 1;
                }

                who->delete_2("exchange");
                send_user( who, "%c%c", 0x26, 0 );    // 关闭交易窗口

                return 1;
        }
        else if( who = find_player(arg) )    // 打开交易窗口
        {
                if( gone_time( me->get_time("exchange") ) < 1 )    // 时间限制
                {
                        me->set_time( "exchange", time() );
                        return 1;
                }
                me->set_time( "exchange", time() );

                me->delete_2("exchange");

                if( me == who ) 
                {
                        notify( "您不能同自己交易。" );
                        return 1;
                }
                if( who->get_login_flag() < 3 )
                {
                        notify( "对方还没有准备就绪呢。" );
                        return 1;
                }
                if( who->is_die() ) return 1;

                if( distance_between(me, who) > 3 )
                {
                        notify( "您距离%s太远了。", who->get_name() );
                        return 1;
                }

                if( who->get_2( "exchange.flag" ) && who->get_2( "exchange.name" ) == me->get_number() )
                {
	                me->set_2( "exchange.flag", 1 );
	                me->set_2( "exchange.name", who->get_number() );                	
                        send_user( me, "%c%c%d%s", 0x26, 1, who->get_number(), who->get_name() );    // 打开交易窗口
                        send_user( who, "%c%c%d%s", 0x26, 1, me->get_number(), me->get_name() );    // 打开交易窗口
                        who->set("exchange_time", 0);
                        me->set("exchange_time", 0);                        
                }
                else
                {
	                if (time()- who->get("exchange_time")<60)
	                {
	                        notify( "%s忙碌中。", who->get_name() );
	                        return 1;                	
	                }       
                        name = me->get_name();
                        name = replace_string(name, "#", "＃");	                         
                        name2 = who->get_name();
                        name2 = replace_string(name2, "#", "＃");	                                                 
	                who->set("exchange_time", time());	   
	                me->set_2( "exchange.flag", 1 );
	                me->set_2( "exchange.name", who->get_number() );       	                             	
                        printf( ECHO "您想与%s(%d)交易，正在等待对方的回应。", name2, who->get_number() );
                        write_user( who, ECHO "%s(%d)想与您交易。", name, me->get_number() );

                        send_user( who, "%c%c%s", 0x59, 2, sprintf("%s(%d)希望与你交易，你是否同意？\n"
                        	ESC "%c\n"ESC"exchange %d\n"
                        	ESC "%c\n"ESC"exchange cancel\n",
                        	name, me->get_number(), 1, me->get_number(), 2) );
                        
                }

                return 1;
        }
        else
        {
//              notify( "您找不到这位玩家。" );
                return 1;
        }
}
