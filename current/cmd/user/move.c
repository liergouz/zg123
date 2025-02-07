#include <ansi.h>
#include <item.h>
#include <equip.h>

// �����������
int main( object me, string arg )
{
        object item, item2;
        int num, num2, amount, amount2, total;
        int i, size, begin, end, flag, count, bag, b, c, d, itemid,rate,level;
        string result, legend,make;

        if( !arg ) return 1;
        else if( sscanf(arg, "%s to %d", arg, num) == 2 ) flag = 2;
        else if( sscanf(arg, "! %s %d", arg, num) == 2 ) flag = 3;
        else if( sscanf(arg, "%s %d", arg, num) == 2 ) flag = 1;
        else return 1;

        if( !objectp( item = present(arg, me, 0, 0) ) )
        {
        	return 1;
        }
        if( me->get_store( sprintf( "%02d", get_d(item) ) ) )
        {
                notify( item->get_name() + "�Ѿ��ϼܣ������ƶ���" );
                send_user( me, "%c%d%c", 0x4e, getoid(item), item->get_amount() );    // ������Ϣ
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
//        if (d>18) d = 18;
        if( flag == 1 )
        {
                num2 = ( get_d(item) - 1 ) / MAX_CARRY * MAX_CARRY;
                if( num < num2 + 1 || num > num2 + MAX_CARRY )    // ͬ��֮��
                {
                        send_user( me, "%c%d%c", 0x4e, getoid(item), item->get_amount() );    // ������Ϣ
                        return 1;
                }
                else if( num2 == MAX_CARRY )    // ����֮��
                {
                        if( num > MAX_CARRY + b  )
                        {
                                send_user( me, "%c%d%c", 0x4e, getoid(item), item->get_amount() );    // ������Ϣ
                                return 1;
                        }
                }
                else if( num2 == MAX_CARRY * 2 )    // Ǭ����֮��
                {
                        if( num > MAX_CARRY*2 + c  )
                        {
                                send_user( me, "%c%d%c", 0x4e, getoid(item), item->get_amount() );    // ������Ϣ
                                return 1;
                        }
                }
                else if( num2 == MAX_CARRY * 3 )    // Ǭ����֮��
                {
                        if( num > MAX_CARRY*3 + d  )
                        {
                                send_user( me, "%c%d%c", 0x4e, getoid(item), item->get_amount() );    // ������Ϣ
                                return 1;
                        }
                }

                if( ( num2 = get_d(item) ) != num )
                {
                        if( objectp( item2 = number_present(me, num, 0, 0) ) )
                        {
                                if( me->get_store( sprintf( "%02d", get_d(item2) ) ) )
                                {
                                        notify( item2->get_name() + "�Ѿ��ϼܣ������ƶ���" );
                                        send_user( me, "%c%d%c", 0x4e, getoid(item), item->get_amount() );    // ������Ϣ
                                        return 1;
                                }
                                if (item->is_specal_move())
                                {
                                	if (item->move_item(me, item, item2)) return 1;
                                }
                                //��ʱ��Ʒ����ʱ�䡣
                                if (item->is_limit_time_item() && item2->is_limit_time_item()
                                && get_file_name(item)==get_file_name(item2) )
                                {
					result = sprintf("�Ƿ�ϳ���Ʒ��\n"
					        	ESC "%c\n" ESC "\nmix2 time_limit %x# %x#\n"
					                , 1, getoid(item), getoid(item2) );
					send_user(me, "%c%s", ';', "������ʱ�����Ƶ���Ʒ�ϳɺ���Ч�ڽ����ӡ�\n�ѹ��ڵ���Ʒ�������δ������Ʒ����Ч�ڣ��������Զ��������\n");
					send_user(me, "%c%c%s", 0x59, 1, result);
                                	return 1;
                                }
                                if (item->get_item_type()==ITEM_TYPE_DIAMOND_3 )
                                {
                                	if (item2->get_item_type()==ITEM_TYPE_DIAMOND_3 && item2->get_diamond_type()!="forge")
                                	{
						result = sprintf("�Ƿ�ϳɱ�ʯ��\n"
					        	ESC "%c\n" ESC "\nmix2 0# %x# %x#\n"
					                , 1, getoid(item), getoid(item2) );
						send_user(me, "%c%c%s", 0x59, 1, result);
                                		return 1;
                                	}
                                	if (item2->is_equip() && item2->get_equip_type()!=HAND_TYPE)
                                	{
						make = item2->get("make");
						level = item->get_level();
						if (make==0) make = "";
						if (strlen(make)!=level-1)
						{
							notify( "��ʯ���Ͳ������޷�����" );
							send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
							return 1;
						}
						switch(level)
						{
							case 1: rate = 100; break;
							case 2: rate = 90; break;
							case 3: rate = 80; break;
							case 4: rate = 70; break;
							case 5: rate = 60; break;
							case 6: rate = 50; break;
							case 7: rate = 40; break;
							case 8: rate = 30; break;
							case 9: rate = 20; break;
	       						default: rate = 10; break;
						}
						if(level!=1 && me->get_vip() && !me->get_save_2("vip_package.trial"))
							rate += 5;
						if (rate>100) rate = 100;
                                		result = sprintf("��ǰװ���ľ����ɹ���Ϊ"HIR"%d"NOR"��\n��ȷ��Ҫ����%s��\n"
							ESC "ȷ��\nmix3 0# %x# %x#\n"
							ESC "ȡ��\n"
						        ,rate, item2->get_name(),getoid(item2), getoid(item));
						send_user(me, "%c%c%w%s", ':', 3, 0, result);
                                		return 1;
                                	}
                                }
                                if (item->get_item_type()==ITEM_TYPE_SHIKE)
                                {
                                	if (item2->is_equip() && item2->get_equip_type()!=HAND_TYPE)
                                	{
                                		if (item->get("mpp")>0 && item2->get_equip_type()!=BOOTS_TYPE)
                                		{
                                			notify( "��Ʒ���Ͳ������޷���Ƕ" );
                                			return 1;
                                		}
                                		if (item->get("hpp")>0 && item2->get_equip_type()!=WAIST_TYPE)
                                		{
                                			notify( "��Ʒ���Ͳ������޷���Ƕ" );
                                			return 1;
                                		}
                                		if (item->get("app")>0 && item2->get_equip_type()!=WEAPON_TYPE)
                                		{
                                			notify( "��Ʒ���Ͳ������޷���Ƕ" );
                                			return 1;
                                		}
                                		if (item->get("dpp")>0 && item2->get_equip_type()!=ARMOR_TYPE)
                                		{
                                			notify( "��Ʒ���Ͳ������޷���Ƕ" );
                                			return 1;
                                		}
                                		if (item->get("cpp")>0 && item2->get_equip_type()!=WEAPON_TYPE)
                                		{
                                			notify( "��Ʒ���Ͳ������޷���Ƕ" );
                                			return 1;
                                		}
                                		if (item->get("double2")>0 && item2->get_equip_type()!=WEAPON_TYPE)
                                		{
                                			notify( "��Ʒ���Ͳ������޷���Ƕ" );
                                			return 1;
                                		}
                                		if (item->get("ppp")>0 && item2->get_equip_type()!=HEAD_TYPE && item2->get_equip_type()!=WAIST_TYPE )
                                		{
                                			notify( "��Ʒ���Ͳ������޷���Ƕ" );
                                			return 1;
                                		}
                                		count = item2->get("app") + item2->get("dpp") + item2->get("cpp") + item2->get("ppp") + item2->get("hpp") + item2->get("mpp") + item2->get("double2");
                                		if (count>0)
                                		{
					                result = sprintf("%s���Ѿ�������Ƕ���Ƿ������\n"
					                        ESC "%c\n"ESC "move ! %x# %d\n"
					                        , item2->get_name(), 1, getoid(item), num );
                                		}
                                		else
                                		{
					                result = sprintf("�Ƿ���%s������Ƕ��\n"
					                        ESC "%c\n" ESC "\nmove ! %x# %d\n"
					                        , item2->get_name(), 1, getoid(item), num );

                                		}
                                		send_user(me, "%c%c%s", 0x59, 1, result);
                                		return 1;
                                	}
                                }
                                if (item->is_mirror())
                                {
                                	if (item2->is_equip()&&item2->get_hide()&& item2->get_equip_type() != HAND_TYPE)
                                	{
					        result = sprintf("�Ƿ��%s���м�����\n"
					                ESC "%c\n" ESC "\nmove ! %x# %d\n"
					                , item2->get_name(), 1, getoid(item), num );
						send_user(me, "%c%c%s", 0x59, 1, result);
						return 1;

                                	}
                                }
                                if (item->is_repair() && item2->is_equip() )
                                {
                                	if (item->move_item(me, item, item2)) return 1;
                                }
/*	��ʯ�ϳ���ĩ����

                                if( num2 <= MAX_CARRY && item->is_diamond_3() && item2->is_diamond_2() )
                                {
                                        ITEM_DIAMOND_D->make_diamond(me, item, item2);
                                        if( item ) send_user( me, "%c%d%c", 0x4e, getoid(item), item->get_amount() );    // ������Ϣ
                                        return 1;
                                }
*/
                                if( item2->is_combined() && get_file_name(item) == get_file_name(item2) && (item->get("special") == item2->get("special")) )
                                {
                                        if( ( amount2 = item2->get_amount() ) < item2->get_max_combined() )
                                        {
                                                amount = item->get_amount();
                                                if( amount + amount2 <= item2->get_max_combined() )
                                                {
                                                        item->set_amount(0);
                                                        item2->set_amount(amount + amount2);
                                                        return 1;
                                                }
                                                else
                                                {
                                                        item->set_amount( amount + amount2 - item2->get_max_combined() );
                                                        item2->set_amount( item2->get_max_combined() );
                                                        return 1;
                                                }
                                        }
                                }

                                set_d(item2, num2);
                        }
                        set_d(item, num);
                        send_user( me, "%c%c%c", 0x5c, num2, num );
                }
        }
        else
        if (flag==3)
        {
                if( ( num2 = get_d(item) ) != num )
                {
                        if( objectp( item2 = number_present(me, num, 0, 0) ) )
                        {
                                if( me->get_store( sprintf( "%02d", get_d(item2) ) ) )
                                {
                                        notify( item2->get_name() + "�Ѿ��ϼܣ������ƶ���" );
                                        send_user( me, "%c%d%c", 0x4e, getoid(item), item->get_amount() );    // ������Ϣ
                                        return 1;
                                }
                                if (item->is_specal_move())
                                {
                                	if (item->move_item2(me, item, item2)) return 1;
                                }
                                if (item->get_item_type()==ITEM_TYPE_SHIKE)
                                {
                                	if (item2->is_equip() && item2->get_equip_type()!=HAND_TYPE)
                                	{
                                		if (item->get("mpp")>0 && item2->get_equip_type()!=BOOTS_TYPE)
                                		{
                                			notify( "��Ʒ���Ͳ������޷���Ƕ" );
                                			return 1;
                                		}
                                		if (item->get("hpp")>0 && item2->get_equip_type()!=WAIST_TYPE)
                                		{
                                			notify( "��Ʒ���Ͳ������޷���Ƕ" );
                                			return 1;
                                		}
                                		if (item->get("app")>0 && item2->get_equip_type()!=WEAPON_TYPE)
                                		{
                                			notify( "��Ʒ���Ͳ������޷���Ƕ" );
                                			return 1;
                                		}
                                		if (item->get("dpp")>0 && item2->get_equip_type()!=ARMOR_TYPE)
                                		{
                                			notify( "��Ʒ���Ͳ������޷���Ƕ" );
                                			return 1;
                                		}
                                		if (item->get("cpp")>0 && item2->get_equip_type()!=WEAPON_TYPE)
                                		{
                                			notify( "��Ʒ���Ͳ������޷���Ƕ" );
                                			return 1;
                                		}
                                		if (item->get("double2")>0 && item2->get_equip_type()!=WEAPON_TYPE)
                                		{
                                			notify( "��Ʒ���Ͳ������޷���Ƕ" );
                                			return 1;
                                		}
                                		if (item->get("ppp")>0 && item2->get_equip_type()!=HEAD_TYPE && item2->get_equip_type()!=WAIST_TYPE )
                                		{
                                			notify( "��Ʒ���Ͳ������޷���Ƕ" );
                                			return 1;
                                		}
                                		item2->set("app", item->get("app"));
						item2->set("dpp", item->get("dpp"));
						item2->set("cpp", item->get("cpp"));
						item2->set("ppp", item->get("ppp"));
						item2->set("hpp", item->get("hpp"));
						item2->set("mpp", item->get("mpp"));
						item2->set("double2", item->get("double2"));
						send_user( me, "%c%d%c", 0x31, getoid(item2), 0 );
						item->remove_from_user();
                        			destruct( item );
                                		return 1;
                                	}
                                }
                                if (item->is_mirror())
                                {
                                	if (item2->is_equip()&&item2->get_hide()&& item2->get_equip_type() != HAND_TYPE)
                                	{
                                		if (item2->get_level()>item->get("level2"))
                                		{
                                			notify( "��ļ����������Լ������װ��" );
                                			return 1;
                                		}
                                		d = get_d(item2);
                                		if (item2->get_item_color()==0 || item2->get_item_color()==4)
                                		{
	                                		i = random(10000);
	                                		if (i<3) "/sys/item/equip"->init_equip_prop_3(item2);
	                                		else
	                                		if (i<603) "/sys/item/equip"->init_equip_prop_1(item2);
							if (item2->get_item_color()!=0 && item2->get_item_color()!=4)
							{
								itemid = "/sys/sys/id"->add_max_itemid(1);
								item2->set_user_id( sprintf("#%d#", itemid) );
								log_file("itemid.dat", sprintf("%s %d %s %s\n", short_time(), itemid, item2->get_name(), "/sys/item/item"->get_pawn_save_string(item2) ));
								legend = sprintf("�������� @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", item->get_name(), me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), item2->get_name(), "/sys/item/item"->get_pawn_save_string(item2), 1, item2->get_user_id(), get_z(me), get_x(me), get_y(me) );
								"/sys/user/cmd"->log_item(legend);
							}
	                                	}
                                		item2->set_hide(0);
                                		item2->add_to_user(d);
                                		item->add_amount(-1);
                                		notify( "������ϡ�" );
                                		return 1;
                                	}
				}
                                if (item->is_repair() && item2->is_equip() )
                                {
                                	if (item->move_item2(me, item, item2)) return 1;
                                }
			}
		}
	}
	else
        {
                if( item->get_name() == "ǮƱ" )
                {
                        notify( "��������ǮƱ��" );
                        send_user( me, "%c%d%c", 0x4e, getoid(item), item->get_amount() );    // ������Ϣ
                        return 1;
                }
                if( item->get_name() == "������Ʒ" )
                {
                        notify( "�������������Ʒ��" );
                        send_user( me, "%c%d%c", 0x4e, getoid(item), item->get_amount() );    // ������Ϣ
                        return 1;
                }
                if(  !( num == 1 )
                &&   !( num == 2 && b>0 )
                &&   !( num == 3 && c>0 )
                &&   !( num == 4 && d>0 ) )
                {
                        send_user( me, "%c%d%c", 0x4e, getoid(item), item->get_amount() );    // ������Ϣ
                        return 1;
                }

                if( num == ( get_d(item) - 1 ) / MAX_CARRY + 1 )    // ͬ��֮��
                {
                        send_user( me, "%c%d%c", 0x4e, getoid(item), item->get_amount() );    // ������Ϣ
                        return 1;
                }
                if( num == 2 )    // ����֮��
                {
                        begin = MAX_CARRY + 1;  end = MAX_CARRY + b;
                }
                else if( num == 3 )    //
                {
                        begin = MAX_CARRY * 2 + 1;  end = MAX_CARRY *2  + c;
                }
                else if( num == 4 )    // Ǭ����֮��
                {
                        begin = MAX_CARRY * 3 + 1;  end = MAX_CARRY *3 + d;
                }
                else
                {
                        begin = 1;  end = MAX_CARRY ;
                }
                if( ( total = USER_INVENTORY_D->can_carry_2(me, item, begin, end) ) < 1 )
                {
                        notify( "��Ӧ��Ʒ��������" );
                        send_user( me, "%c%d%c", 0x4e, getoid(item), item->get_amount() );    // ������Ϣ
                        return 1;
                }
                if( item->is_combined() )
                {
                        if( total > item->get_amount() ) total = item->get_amount();

                        amount = USER_INVENTORY_D->carry_combined_item_2(me, item, total, begin, end);

                        if( amount > 0 && item->set_amount(amount) )
                        {
                                if( sizeof_inventory(me, begin, end) >= end - begin + 1 )
                                {
                                        notify( "Ŀ����Ʒ��������" );
                                        send_user( me, "%c%d%c", 0x4e, getoid(item), item->get_amount() );    // ������Ϣ
                                        return 1;
                                }

                                for( i = 0, size = end - begin + 1; i < size; i ++ )
                                        if( !number_present(me, i + begin, begin, end) ) break;    // Ѱ�ҿ�λ

                                if( i < size )
                                {
                                        send_user( me, "%c%c%c", 0x5c, get_d(item), i + begin );
                                        set_d(item, i + begin);
                                }
                        }
                        else    item->add_amount( -total );
                }
                else
                {
                        if( sizeof_inventory(me, begin, end) >= end - begin + 1 )
                        {
                                notify( "Ŀ����Ʒ��������" );
                                send_user( me, "%c%d%c", 0x4e, getoid(item), item->get_amount() );    // ������Ϣ
                                return 1;
                        }

                        for( i = 0, size = end - begin + 1; i < size; i ++ )
                                if( !number_present(me, i + begin, begin, end) ) break;    // Ѱ�ҿ�λ

                        if( i < size )
                        {
                                send_user( me, "%c%c%c", 0x5c, get_d(item), i + begin );
                                set_d(item, i + begin);
                        }
                }
        }

        return 1;
}
