
#include <ansi.h>
#include <equip.h>
#include <item.h>
#include <effect.h>
#include <city.h>
#include <public.h>

int buy_store_item(object buyer, object owner,object item, int amount, int pos);
int buy_store_pet(object buyer, object owner, object pet, int pos);

// 函数：命令处理
int main( object me, string arg )
{
        mapping list;
        object city, who, *inv, item, item2, money,pet,orgnpc,org_master;
        string *key, id, file, result, legend,name, dtype;
        int what, total, amount, price,value,price1, itemid;
        int z, x, y, p, i, size, count;

//        if( gone_time( me->get_time("buy") ) < 1 )    // 时间限制
//      {
//                me->set_time( "buy", time() );
//                return 1;
//        }
	if (is_gm(me)) return 1;
        if (arg=="close")
        {
        	if (me->get("buy_time") && get_effect(me, EFFECT_PROGRESS2 ) )
        	{
        		me->set("buy_time", 0);
        		set_effect(me, EFFECT_PROGRESS2, 1 );
        	}
        	return 1;
        }
        me->set_time( "buy", time() );

        if( !arg || sscanf(arg, "%s %s", id, arg) != 2 ) return 1;

        if( !objectp( who = find_char(id) ) ) return 1;

        if( !who->is_seller() && !who->is_seller_2() && !who->is_trader() && !who->is_store_open() && !who->is_bonus_seller() && !who->is_item_seller() ) return 1;

        if( (time()-me->get("buy_time")>300) && !inside_screen_2(me, who) )
        {
                notify( "您距离%s太远了。", who->get_name() );
                return 1;
        }

        me->to_front_eachother(who);
        z = get_z(me), x = get_x(me), y = get_y(me);;

        total = 1;

        if(     sscanf( arg, "%d %d", what, total ) != 2    // what, total 顺序不能反，sscanf 有缺陷
        &&      sscanf( arg, "%d", what ) != 1 )
        {
                notify( "您想购买什么东西？" );
                return 1;
        }
        if( total < 1 )
        {
                notify( "您购买的个数得大于０。" );
                return 1;
        }

        if( who->is_seller() > 0 && who->is_seller()!=2 )
        {
                if( !stringp( file = who->get_2( sprintf( "good.%02d", what ) ) ) )
                {
                        notify( who->get_name() + "没有这样东西。" );
                        return 1;
                }
                value = who->get_2( sprintf( "price.%02d", what ) );
                if ( !value ) value = file->get_value();
                if( value < 1 )
                {
                        notify( who->get_name() + "不想跟你交易。" );
                        return 1;
                }
		price1 = value;
                if( ( amount = USER_INVENTORY_D->can_carry_3( me, load_object(file) ) ) < 1 )
                {
                        notify( "您携带的东西太多了。" );
                        return 1;
                }
                if( total > amount ) total = amount;
/*
                if( city = CITY_D->get_city_object(who) )
                {
                        if( me->get_city_name() == who->get_city_name() )
                                value += value * city->get_buy_tax() / 100;
                        else    value += value * city->get_buy_tax_2() / 100;
                }
*/
                price = value * total;
                if( price<1 || value != price / total )	// 避免溢出出问题
                {
                        notify( who->get_name() + "不想跟你交易。" );
                        return 1;
                }
                if( price > me->get_cash() )
                {
                        notify( "您手上的现金不够。" );
                        return 1;
                }

                if( file->is_combined() )
                {
                        if( amount = USER_INVENTORY_D->carry_combined_item_3( me, load_object(file), total ) )
                        {
                                item = new(file);
                                item->set_hide(0);
                                item->set_amount(amount);
				if (item->is_record())
				{
					itemid = "/sys/sys/id"->add_max_itemid(1);
					item->set_user_id( sprintf("#%d#", itemid) ); 
					log_file("itemid.dat", sprintf("%s %d %s %s\n", short_time(), itemid, item->get_name(), "/sys/item/item"->get_pawn_save_string(item) ));
					result = sprintf("购买 @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", who->get_name(), me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), amount, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
					"/sys/user/cmd"->log_item(result);
				}				
                                if( p = item->move2(me) )
                                {
                                        item->add_to_user(p);
                                }
                                else if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                                {
                                        item->add_to_scene(z, p / 1000, p % 1000);
                                }
                        }
                }
                else for( i = 0; i < total; i ++ )
                {
                        item = new(file);
			item->set_hide(0);
			if (item->is_record())
			{
				itemid = "/sys/sys/id"->add_max_itemid(1);
				item->set_user_id( sprintf("#%d#", itemid) ); 
				log_file("itemid.dat", sprintf("%s %d %s %s\n", short_time(), itemid, item->get_name(), "/sys/item/item"->get_pawn_save_string(item) ));
				result = sprintf("购买 @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", who->get_name(), me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), amount, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
				"/sys/user/cmd"->log_item(result);
			}			
                        if( p = item->move2(me) )
                        {
                                item->add_to_user(p);
                        }
                        else if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item->add_to_scene(z, p / 1000, p % 1000);
                        }
                }

                me->add_cash2( -price );  me->add_gold_log("buy", price);
                //me->log_money("购买", -price);
                result = sprintf("扣减 %s,%d,%s,%s @%s 金 0 %d 0 %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), who->get_name(), price, get_z(me), get_x(me), get_y(me) );
                "/sys/user/cmd"->log_item(result);
                "/sys/sys/count"->add_use("buy", price);
                tell_user(me,  "您向%s买下%s。", who->get_name(), file->get_name() );

                if( city = CITY_D->get_city_object(who) )
                {
                        total *= price1;
                        city->add_tax( price - total );
                        city->add_cash( total );
                }
        }
        else if( who->is_seller()==2 )  // 云游商人
        {
                if( gone_time(who->get("yunyou_buy_time")) < 5  )
                {
                        notify( who->get_name() + "要再过5秒才有得卖。" );
                        return 1;
                }
                if( !stringp( file = who->get_2( sprintf( "good.%02d", what ) ) ) )
                {
                        notify( who->get_name() + "没有这样东西。" );
                        return 1;
                }
                value = who->get_2( sprintf( "price.%02d", what ) );
                if ( !value ) value = file->get_value();
                if( value < 1 )
                {
                        notify( who->get_name() + "不想跟你交易。" );
                        return 1;
                }
                dtype = file[<4..<1];               
		if (file->get_item_type()==ITEM_TYPE_DIAMOND_3 && who->get_save_2("diamond."+dtype)>=100)
		{			
			value = value * who->get_save_2("diamond."+dtype)/100;
			total = 1;
		}
		price1 = value;
                if( ( amount = USER_INVENTORY_D->can_carry_3( me, load_object(file) ) ) < 1 )
                {
                        notify( "您携带的东西太多了。" );
                        return 1;
                }
                if (total>who->get_2( sprintf( "list.%02d", what ) ) )
                {
                        notify( who->get_name() + "没有这么多东西。" );
                        return 1;
                }

                if( city = CITY_D->get_city_object(who) )
                {
                        if( me->get_city_name() == who->get_city_name() )
                                value += value * city->get_buy_tax() / 100;
                        else    value += value * city->get_buy_tax_2() / 100;
                }

                price = value * total;
                if( price<1 || value != price / total )	// 避免溢出出问题
                {
                        notify( who->get_name() + "不想跟你交易。" );
                        return 1;
                }
                if( price > me->get_cash() )
                {
                        notify( "您手上的现金不够。" );
                        return 1;
                }

                if( file->is_combined() )
                {
                        if( amount = USER_INVENTORY_D->carry_combined_item_3( me, load_object(file), total ) )
                        {
                                item = new(file);
                                item->set_hide(0);
                                item->set_amount(amount);
				if (item->is_record())
				{
					itemid = "/sys/sys/id"->add_max_itemid(1);
					item->set_user_id( sprintf("#%d#", itemid) ); 
					log_file("itemid.dat", sprintf("%s %d %s %s\n", short_time(), itemid, item->get_name(), "/sys/item/item"->get_pawn_save_string(item) ));
					result = sprintf("购买 @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", who->get_name(), me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), amount, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
					"/sys/user/cmd"->log_item(result);
				}                                
                                if( p = item->move2(me) )
                                {
                                        item->add_to_user(p);
                                }
                                else if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                                {
                                        item->add_to_scene(z, p / 1000, p % 1000);
                                }
                        }
                }
                else for( i = 0; i < total; i ++ )
                {
                        item = new(file);
			item->set_hide(0);
			if (item->is_record())
			{
				itemid = "/sys/sys/id"->add_max_itemid(1);
				item->set_user_id( sprintf("#%d#", itemid) ); 
				log_file("itemid.dat", sprintf("%s %d %s %s\n", short_time(), itemid, item->get_name(), "/sys/item/item"->get_pawn_save_string(item) ));
				result = sprintf("购买 @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", who->get_name(), me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), amount, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
				"/sys/user/cmd"->log_item(result);
			}			
                        if( p = item->move2(me) )
                        {
                                item->add_to_user(p);
                        }
                        else if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item->add_to_scene(z, p / 1000, p % 1000);
                        }
                }

                me->add_cash2( -price );  me->add_gold_log("buy", price);
                result = sprintf("扣减 %s,%d,%s,%s @%s 金 0 %d 0 %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), who->get_name(), price, get_z(me), get_x(me), get_y(me) );
                "/sys/user/cmd"->log_item(result);
                "/sys/sys/count"->add_use("buy", price);                
		if( who->add_2( sprintf( "list.%02d", what ), -total ) < 1 ) who->delete_2( sprintf( "good.%02d", what ) );
		if (file->get_item_type()==ITEM_TYPE_DIAMOND_3 && who->get_save_2("diamond."+dtype)>=100)
		{
			who->add_save_2("diamond."+dtype, 3);
			who->save();
			who->set("yunyou_buy_time",time());
			CHAT_D->sys_channel(0,sprintf(HIR"%s"HIY"眼疾手快，以"HIR"%d"HIY"的价格买到了%s的"HIR"%s"HIY"。",me->get_name(),price,who->get_name(),file->get_name()));
			tell_user(me,  "您以%d的价格向%s买下 %s，%s晶石物价指数变为%d。", price, who->get_name(), file->get_name(), file->get_name(), who->get_save_2("diamond."+dtype) );
		}
		else
			tell_user(me,  "您向%s买下 %s。", who->get_name(), file->get_name() );
        }
        else if( who->is_seller_2() )
        {
                if( !stringp( file = who->get_2( sprintf( "good.%02d", what ) ) ) )
                {
                        notify( who->get_name() + "没有这样东西。" );
                        return 1;
                }
                value = who->get_2( sprintf( "price.%02d", what ) );
                if ( !value ) value = file->get_value();
                if( value < 1 )
                {
                        notify( who->get_name() + "不想跟你交易。" );
                        return 1;
                }
                if( total > ( size = who->get_2( sprintf( "list.%02d", what ) ) ) )
                {
                        notify( "%s现在只有 %s 数量不足。",
                                who->get_name(), file->get_name() );
                        return 1;
                }

                if( ( amount = USER_INVENTORY_D->can_carry_3( me, load_object(file) ) ) < 1 )
                {
                        notify( "您携带的东西太多了。" );
                        return 1;
                }
                if( total > amount ) total = amount;
		price1 = value;
                if( city = CITY_D->get_city_object(who) )
                {
                        if( me->get_city_name() == who->get_city_name() )
                                value += value * city->get_buy_tax() / 100;
                        else    value += value * city->get_buy_tax_2() / 100;
                }

                price = value * total;
                if( price<1 || value != price / total )	// 避免溢出出问题
                {
                        notify( who->get_name() + "不想跟你交易。" );
                        return 1;
                }
                if( price > me->get_cash() )
                {
                        notify( "您手上的现金不够。" );
                        return 1;
                }

                if( who->add_2( sprintf( "list.%02d", what ), -total ) < 1 ) who->delete_2( sprintf( "good.%02d", what ) );

                if( file->is_combined() )
                {
                        if( amount = USER_INVENTORY_D->carry_combined_item_3( me, load_object(file), total ) )
                        {
                                item = new(file);
                                item->set_hide(0);
                                item->set_amount(amount);
				if (item->is_record())
				{
					itemid = "/sys/sys/id"->add_max_itemid(1);
					item->set_user_id( sprintf("#%d#", itemid) ); 
					log_file("itemid.dat", sprintf("%s %d %s %s\n", short_time(), itemid, item->get_name(), "/sys/item/item"->get_pawn_save_string(item) ));
					result = sprintf("购买 @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", who->get_name(), me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), amount, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
					"/sys/user/cmd"->log_item(result);
				}
                                if( p = item->move2(me) )
                                {
                                        item->add_to_user(p);
                                }
                                else if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                                {
                                        item->add_to_scene(z, p / 1000, p % 1000);
                                }
                        }
                }
                else for( i = 0; i < total; i ++ )
                {
                        item = new(file);
			item->set_hide(0);
			if (item->is_record())
			{
				itemid = "/sys/sys/id"->add_max_itemid(1);
				item->set_user_id( sprintf("#%d#", itemid) ); 
				log_file("itemid.dat", sprintf("%s %d %s %s\n", short_time(), itemid, item->get_name(), "/sys/item/item"->get_pawn_save_string(item) ));
				result = sprintf("购买 @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", who->get_name(), me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), amount, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
				"/sys/user/cmd"->log_item(result);
			}			
                        if( p = item->move2(me) )
                        {
                                item->add_to_user(p);
                        }
                        else if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item->add_to_scene(z, p / 1000, p % 1000);
                        }
                }

                me->add_cash2( -price );  me->add_gold_log("buy", price);
		result = sprintf("扣减 %s,%d,%s,%s @%s 金 0 %d 0 %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), who->get_name(), price, get_z(me), get_x(me), get_y(me) );
                "/sys/user/cmd"->log_item(result);
                "/sys/sys/count"->add_use("buy", price);
                tell_user(me, "您向%s买下 %s。", who->get_name(), file->get_name() );

                if( city = CITY_D->get_city_object(who) )
                {
                        total *= price1;
                        city->add_tax( price - total );
                        city->add_cash( total );
                }
        }
        else if( who->is_trader() && (me->is_businessman() || me->get_save_2("mastertask.type")==11 || me->get_save_2("orgtask3.type") ) )    // 国家商人
        {
                total = 1;    // 只能一个个买

                if( !stringp( file = who->get_2( sprintf( "good.%02d", what ) ) ) )
                {
                        notify( who->get_name() + "没有这样东西。" );
                        return 1;
                }
                if( ( amount = USER_INVENTORY_D->can_carry_3( me, load_object(file) ) ) < 1 )
                {
                        notify( "您携带的东西太多了。" );
                        return 1;
                }
                if( ( price = file->get_buy_price() + file->get_buy_range() * who->get_buy_rate() / 1000 ) < 1 )
                {
                        notify( who->get_name() + "不想跟你交易。" );
                        return 1;
                }
                if( total > ( size = who->get_2( sprintf( "list.%02d", what ) ) ) )
                {
                        notify( "%s现在只有 %s 数量不足。",
                                who->get_name(), file->get_name() );
                        return 1;
                }

                if( !objectp( money = present("钱票", me, 1, MAX_CARRY*4) ) )
                {
                        if( !objectp( money = present("银票", me, 1, MAX_CARRY) ) )
                        {
                                notify( "做生意得得有钱票或者银票。" );
                                return 1;
                        }
                }
                if (money->get_item_type()==ITEM_TYPE_CHEQUE)
                {
                	if (me->get_save_2("orgtask3.type")==0)
                        {
                                notify( "你没有领取帮派经商任务。" );
                                return 1;
                        }
                        if (money->get_money()>=money->get_orgin_money()*3/2)
                        {
                                notify( "你已完成了帮派经商的任务。" );
                                return 1;
                        }
                }
                if (money->get_item_type()==ITEM_TYPE_CHEQUE2)
                {
                        if (me->get_save_2("mastertask.type")!=11)
                        {
                                notify( "你没有接筹集资金的任务。" );
                                return 1;
                        }
                        if (me->get_save_2("mastertask.status")==99)
                        {
                                notify( "你已经完成筹集资金的任务。" );
                                return 1;
                        }
			if ( money->get_money()-money->get_orgin_money()>=me->get_save_2("mastertask.targetxy"))
	                {
	                        send_user(me, "%c%s", '!', "你的银票金额已经达到了任务上限，无法再用于商品的购买。" );
	                        return 1;
	                }
                }
                if( price * total > money->get_money() )
                {
                        notify( "您手上钱票的资金不够。" );
                        return 1;
                }
                if( who->add_2( sprintf( "list.%02d", what ), -total ) < 1 ) who->delete_2( sprintf( "good.%02d", what ) );
                for( i = 0; i < total; i ++ )
                {
                        item = new(file);
                        item->set_hide(0);
                        item->set_buyin(price);
                        who->add_buy_rate(1);

                        if( p = item->move2(me) )
                        {
                                item->add_to_user(p);
                        }
                        else if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item->add_to_scene(z, p / 1000, p % 1000);
                        }

                }

                money->add_money( -price * total );
                money->do_look(me);
                tell_user(me, "您花 %d 金向%s买下 %s。", price * total, who->get_name(), item->get_name() );
        }
        else if( who->is_store_open() )
        {
                if (who==me)
                {
                        notify( "自己的东西就不用买了吧？" );
                        return 1;
                }
                if( !mapp( list = who->get_store_dbase() ) || !sizeof( key = keys(list) ) )
                {
                        send_user( me, "%c%s", '!', who->get_name() + "的东西全都卖光了。" );
                        return 1;
                }
                if( ( price = list[ sprintf( "%02d", what ) ] ) < 1 )
                {
                	send_user( me, "%c%s", '!', who->get_name() + "不想跟你交易。" );
                        return 1;
                }
                price1 = price;
                price *= total;
                if( price<1 || price1 != price / total )	// 避免溢出出问题
                {
                        notify( who->get_name() + "不想跟你交易。" );
                        return 1;
                }                

                if( price > me->get_cash() )
                {
                        notify( "您手上的现金不够。" );
                        return 1;
                }
                
                if ( what < 100 )	//物品
                {
	                if( !objectp( item = number_present(who, what, 1, MAX_CARRY) ) )
	                {
	                	send_user( me, "%c%s", '!', who->get_name() + "不想跟你交易。" );
	                        return 1;
	                }
	                name = item->get_name();
	                total = buy_store_item(me,who,item,total,what);
	        }
	        else	//宠物
	        {
	        	if ( !(id=who->get_store_beast_id(sprintf("%2d",what))) || !objectp(pet=find_char(id)) || !pet->is_pet() || pet->get_owner() != who )
	        	{
	                	send_user( me, "%c%s", '!', who->get_name() + "不想跟你交易。" );
	                        return 1;
	                }	
	        	name = pet->get_firstname();
	        	total = buy_store_pet(me,who,pet,what);
	        }
                if ( !total )
                	return 1;
		price = price1 * total;
                result = sprintf( "%s用 %d 金向您买下 %s，您交纳税金%d。",
                        me->get_name(), price, name, price/100 );
log_file("wu_duty.dat", sprintf("%s %s(%d) 交税金 %d\n", short_time(), me->get_id(), me->get_number(), price/100));
		send_user(who, "%s", ECHO + result);
                send_user(who, "%c%c%s", 0x7b, 0xfe, result);    // 交易记录
                send_user(who, "%c%c%d", 0x7b, 0xfd, price);    // 交易记录
                tell_user(me, "您花 %d 向%s买下 %s。",
                        price, who->get_name(), name );
                me->add_cash2( -price );  me->add_gold_log("buy2", price);
//                me->log_money("摆摊买", -price);
                who->add_cash2(price-price/100);  who->add_gold_log("sell2", price-price/100);
//		who->log_money("摆摊卖", price*99/100);
		if ( WUSHUANG->get_save("wg_duty") < 20000000 )
		{
			if ( (WUSHUANG->get_save("wg_duty")+price/100) > 20000000 )
			{
				WUSHUANG->set_save("wg_duty",20000000);
			        WUSHUANG->get_save_2("occupy_org");
			        orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", WUSHUANG->get_save_2("occupy_org") ) );
				org_master = find_char(orgnpc->get_master());
				MAILBOX->sys_mail(orgnpc->get_master_id(),orgnpc->get_master(),HIW"    您所占领的无双城税金已达上限，税金将不再增加！！");
			}
			else
				WUSHUANG->add_save("wg_duty",price/100);
			WUSHUANG->save();
		}
		result = sprintf("买摆摊扣减 %s,%d,%s,%s %s,%d,%s,%s 金 0 %d 0 %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), price, get_z(who), get_x(who), get_y(who) );
		"/sys/user/cmd"->log_item(result);
                if( who->is_npc() )
                        send_user( me, "%c%c%c%d%s", 0x28, 0, 0, getoid(who), sprintf( "%-12s%s", who->get_name(), "" ) );
                else    send_user( me, "%c%c%c%d%s", 0x28, 0, 1, who->get_number(), sprintf( "%-12s%s", who->get_name(), me->get_store_name() ) );
                if( !mapp( list = who->get_store_dbase() ) || !( size = sizeof( key = keys(list) ) ) ) return 1;
                for( i = 0; i < size; i ++ )
                {
                        what = to_int( key[i] );
                        if ( what < 100 )	//物品列表
                        {
	                        if( item = number_present(who, what, 1, MAX_CARRY) )
	                                send_user( me, "%c%c%d%w%w%c%c%s", 0x28, what, list[ key[i] ],
	                                        item->get_picid_2(), item->get_amount(), 0, item->get_item_color(), item->get_name() );
                	}
                	else		//宠物列表
                	{
                		if ( (pet=find_char(who->get_store_beast_id(key[i]))) && pet->get_owner() == who && pet->get("store") )
	                                send_user( me, "%c%c%d%w%w%c%c%s", 0x28, what, list[ key[i] ],
	                                        pet->get_char_picid(), 1, 0, 0, pet->get_firstname() );
                			
                	}
                }
        }
        else if( who->is_bonus_seller() )
        {
                if( !stringp( file = who->get_2( sprintf( "good.%02d", what ) ) ) )
                {
                        notify( who->get_name() + "没有这样东西。" );
                        return 1;
                }
                if( ( price = file->get_bonus_value() ) < 1 )
                {
                        notify( who->get_name() + "不想跟你兑换。" );
                        return 1;
                }

                if( ( amount = USER_INVENTORY_D->can_carry_3( me, load_object(file) ) ) < 1 )
                {
                        notify( "您携带的东西太多了。" );
                        return 1;
                }
                if( total > amount ) total = amount;

                price *= total;

                if( price > me->get_bonus() )
                {
                        notify( "您的功德点数不够。" );
                        return 1;
                }

                if( file->is_combined() )
                {
                        if( amount = USER_INVENTORY_D->carry_combined_item( me, load_object(file), total ) )
                        {
                                item = new(file);
                                item->set_hide(0);
                                item->set_amount(amount);

                                if( p = item->move2(me) )
                                {
                                        item->add_to_user(p);
                                }
                                else if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                                {
                                        item->add_to_scene(z, p / 1000, p % 1000);
                                }
                        }
                }
                else for( i = 0; i < total; i ++ )
                {
                        item = new(file);
			item->set_hide(0);
                        if( p = item->move2(me) )
                        {
                                item->add_to_user(p);
                        }
                        else if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item->add_to_scene(z, p / 1000, p % 1000);
                        }
                }

                me->add_bonus( -price );
                notify( "您向%s兑到 %s。", who->get_name(), file->get_name() );
        }
        else if( who->is_item_seller() )    // 用点卡买道具！！
        {
                // 目前抄普通小贩 is_seller()，只是取消 tax 而已

                if( !me->get_pay_money_buy_item() )    // 可以通过点数购买道具
                {
                	if (me->get("paycount")<0)
                	{
                		notify( "您的帐号余额不足，如果您已充值，请退出游戏再进以购买道具。" );
                		return 1;
                	}
                        if( !stringp( file = who->get_2( sprintf( "good.%02d", what ) ) ) )
                        {
                                notify( who->get_name() + "没有这样东西。" );
                                return 1;
                        }
                        if( ( price = file->get_item_value() ) < 1 )
                        {
                                notify( who->get_name() + "不想跟你交易。" );
                                return 1;
                        }

                        if( ( amount = USER_INVENTORY_D->can_carry_3( me, load_object(file) ) ) < 1 )
                        {
                                notify( "您携带的东西太多了。" );
                                return 1;
                        }
                        if( total > amount ) total = amount;

                        price *= total;

                        me->set_pay_money_buy_item(1);    // 通过点数购买道具中
                        me->set_pay_type(1);
                        me->set_buy_item_cmd_string( sprintf("%x# %d %d", getoid(who), what, total) );
log_file("buyitem.dat", sprintf("%s %s(%d) 购买%s %d\n", short_time(), me->get_id(), me->get_number(), file->get_name(), total));
			if (MAIN_D->get_host_type()==4||MAIN_D->get_host_type()==0)
			{
	                	db_user_pay( me, sprintf( "%s:80\n"
	                		"GET http:/""/%s/purchase.php?t=%s&u=%d&o=%d&n=%d&m=%d&c=%d&ip=%s&r=%d&h=%d\r\n", MAIN_D->get_php_ip(),
	                		MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), total, price, file->get_item_number(), get_ip_name(me), MAIN_D->get_region(), MAIN_D->get_host() ) );
log_file("php.dat", sprintf( "%s:80\n"
	                		"GET http:/""/%s/purchase.php?t=%s&u=%d&o=%d&n=%d&m=%d&c=%d&ip=%s&r=%d&h=%d\n", MAIN_D->get_php_ip(),
	                		MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), total, price, file->get_item_number(), get_ip_name(me), MAIN_D->get_region(), MAIN_D->get_host() ) );	        	                
			}
			else
                	db_user_pay( me, sprintf( "%s:80\n"
				"GET /xq2/buy.php?id=%s&time=%d&region=%d&host=%d&item=%d&point=%d&ip=%s\r\n", MAIN_D->get_php_ip(),
        	                rawurlencode( me->get_id() ), time(), MAIN_D->get_region(), MAIN_D->get_host(), file->get_item_number(), price, get_ip_name(me) ) );    // 扣点！
                }
                else if( me->get_pay_money_buy_item() == 8 && me->get_pay_type()==1 )    // 通过点数购买道具成功！
                {
                        me->set_pay_money_buy_item(0);    // 取消通过点数购买道具
                        me->set_pay_type(0);

                        if( !stringp( file = who->get_2( sprintf( "good.%02d", what ) ) ) )
                        {
log_file("buyitem.dat", sprintf("%s %s(%d) 没有购买对象\n", short_time(), me->get_id(), me->get_number()));
                                notify( who->get_name() + "没有这样东西。" );
                                return 1;
                        }
                        if( ( price = file->get_item_value() ) < 1 )
                        {
log_file("buyitem.dat", sprintf("%s %s(%d) 购买商品不对\n", short_time(), me->get_id(), me->get_number()));
                                notify( who->get_name() + "不想跟你交易。" );
                                return 1;
                        }

                        if( ( amount = USER_INVENTORY_D->can_carry_3( me, load_object(file) ) ) < 1 )
                        {
log_file("buyitem.dat", sprintf("%s %s(%d) 购买不足空位\n", short_time(), me->get_id(), me->get_number()));
                                notify( "您携带的东西太多了。" );
                                return 1;
                        }
                        if( total > amount ) total = amount;

                        price *= total;

                        if( file->is_combined() )
                        {
                                if( amount = USER_INVENTORY_D->carry_combined_item( me, load_object(file), total ) )
                                {
                                        item = new(file);
                                        item->set_hide(0);
                                        item->set_amount(amount);
                                        count = "/sys/sys/count"->add_buy_count(1);
                                        itemid = "/sys/sys/id"->add_max_itemid(1);
                                        item->set_user_id( sprintf("#%d#", itemid) ); 
                                        log_file("itemid.dat", sprintf("%s %d %s %s\n", short_time(), itemid, item->get_name(), "/sys/item/item"->get_pawn_save_string(item) ));
					result = sprintf("点数购买 @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", who->get_name(), me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), amount, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
					"/sys/user/cmd"->log_item(result);
                                        if( p = item->move2(me) )
                                        {
                                                item->add_to_user(p);
                                        }
                                        else if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                                        {
                                                item->add_to_scene(z, p / 1000, p % 1000);
                                        }
                                }
                        }
                        else for( i = 0; i < total; i ++ )
                        {
                                item = new(file);
				item->set_hide(0);
                                count = "/sys/sys/count"->add_buy_count(1);
                                itemid = "/sys/sys/id"->add_max_itemid(1);
				item->set_user_id( sprintf("#%d#", itemid) );                                 
                                log_file("itemid.dat", sprintf("%s %d %s %s\n", short_time(), itemid, item->get_name(), "/sys/item/item"->get_pawn_save_string(item) ));
				result = sprintf("点数购买 @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", who->get_name(), me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
				"/sys/user/cmd"->log_item(result);				
                                if( p = item->move2(me) )
                                {
                                        item->add_to_user(p);
                                }
                                else if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                                {
                                        item->add_to_scene(z, p / 1000, p % 1000);
                                }
                        }
log_file("buyitem.dat", sprintf("%s %s(%d) 购买%s成功 %d %d\n", short_time(), me->get_id(), me->get_number(), file->get_name(), total, price));
                        tell_user(me,  "您向%s买下%s。", who->get_name(), file->get_name() );
                }
        }

        return 1;
}
//摆摊购买物品 返回实际购买数量
int buy_store_item(object me, object who,object item, int total,int pos)
{
	object item2;
	int amount,p,z,y,x;
	string legend;
	
	z = get_z(me); x = get_x(me); y = get_y(me);
	if( item->get_bind()==2 || item->get_bind()==3 || item->get_bind()==4  )
        {
                notify( "已经绑定的东西不能购买。" );
                return 0;
        }
        if( ( amount = USER_INVENTORY_D->can_carry_3(me, item) ) < 1 )
        {
                notify( "您携带的东西太多了。" );
                return 0;
        }
        if( total > amount ) total = amount;

        if( item->is_combined() )    // total 不能超过 get_amount()
        {
                if( total > item->get_amount() ) total = item->get_amount();
        }
        else    total = 1;    // 非叠加物品数量为 1

	if (item->is_record() )
	{
		legend = sprintf("摆摊卖 %s,%d,%s,%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), total, item->get_user_id(), get_z(who), get_x(who), get_y(who) );
		"/sys/user/cmd"->log_item(legend);		
	}
        if( item->is_combined()&&(item->get_max_combined()>1))
        {
                if( amount = USER_INVENTORY_D->carry_combined_item(me, item, total) )
                {
                        item2 = new( get_file_name(item) );
                        if ( item->get("special") )
                        	item2->set("special",item->get("special") );
                        item2->set_amount(amount);

                        if( p = item2->move2(me) )
                        {
                                item2->add_to_user(p);
                        }
                        else if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item2->add_to_scene(z, p / 1000, p % 1000);
                        }
                }

                if( !item->add_amount( -total ) ) who->delete_store( sprintf( "%02d", pos ) );
        }
        else
        {
                send_user( who, "%c%d", 0x2d, getoid(item) );
                if( p = item->move2(me) )
                {
                        item->add_to_user(p);
                }
                else if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                {
                        item->add_to_scene(z, p / 1000, p % 1000);
                }
                who->delete_store( sprintf( "%02d", pos ) );
        }

	return total;	
}
//摆摊购买宠物????
int buy_store_pet(object me, object who, object pet, int pos)
{
	if ( pet->get_owner() != who )
		return 0;
	if ( NPC_PET_D->can_carry(me,pet) !=1 )
	{
		send_user(me,"%c%s",'!',"你不能携带这个宠物。");	
		return 0;
	}
	if ( me->get_beast_amount() + 1 > me->get_beast_max_amount() )
	{
		send_user(me,"%c%s",'!',"你不能携带太多的宠物。");	
		return 0;
	}
	if ( pet->get("show") )
		USER_BEAST_D->hide(who,pet);
	USER_BEAST_D->remove_from_user(who,pet);
	pet->set_owner(0);
	pet->set_owner(me);
	me->add_beast(pet);
	pet->add_faith(-20);
	pet->send_info();
	pet->save();
	pet->delete("store");
	return 1;
}