#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <skill.h>
#include <item.h>
int pet_use(object me,string arg);

// 函数：命令处理
int main( object me, string arg )
{
        object item, who;
        string id, id2, arg1, key, func, *allkey, result, legend;
        int busy, z, x, y, size, flag;
	if( me->is_store_open() )
	{
		send_user(me, "%c%s", '!', "摆摊时不能使用道具。");
		return 0;
	}
	allkey = explode(arg, " ");
	size = sizeof(allkey);
	if (size==3 && allkey[1]=="pet")
	{
		return pet_use(me,arg);	
	}
	if (size==2 && allkey[0]=="!")
	{
		id = allkey[1];
		if( !objectp( item = present(id, me, 1, MAX_CARRY*4) ) ) return 1;
		if (item->is_record()) 
		{
			legend = sprintf("使用 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
			flag = 1;
		}
		if( !item->confirm_use(me) )
	        {
	        	if (!item && flag==1) "/sys/user/cmd"->log_item(legend);
	                return 1;
	        }
                if (item->is_record())
                {
			"/sys/user/cmd"->log_item(legend);
                }
	        if( item->is_combined() ) 
	                item->add_amount(-1);
	        else 
	        {
	                item->remove_from_user();
	                destruct(item);
	        }
		return 1;		
		
	}
	else
	if (size==5 && allkey[1]=="for")
	{
		id = allkey[0];
		z = to_int(allkey[2]);
		x = to_int(allkey[3]);
		y = to_int(allkey[4]);
		if( !objectp( item = present(id, me, 1, MAX_CARRY*4) ) ) return 1;		
                if (item->is_record())
                {
                	legend = sprintf("使用 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
                	flag = 1;			
                }		
		if( !item->get_use_effect(me, z, x, y) )
	        {
	        	if (!item && flag==1) "/sys/user/cmd"->log_item(legend);
	                return 1;
	        }
                if (item->is_record())
                {
			"/sys/user/cmd"->log_item(legend);
                }	        
	        if( item->is_combined() ) 
	                item->add_amount(-1);
	        else 
	        {
	                item->remove_from_user();
	                destruct(item);
	        }
		return 1;
	}
	if (size==3 && allkey[1]=="for")
	{
		id = allkey[0];
		id2 = allkey[2];
		who = find_char(id2);
		if( !objectp( item = present(id, me, 1, MAX_CARRY*4) ) ) return 1;		
		if( !objectp(who)) return 1;
                if (item->is_record())
                {
                	legend = sprintf("使用 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
                	flag = 1;			
                }		
		if( !item->get_use_effect(me, who) )
	        {
	        	if (!item && flag==1) "/sys/user/cmd"->log_item(legend);
	                return 1;
	        }
                if (item->is_record())
                {
			"/sys/user/cmd"->log_item(legend);
                }	        
	        if( item->is_combined() ) 
	                item->add_amount(-1);
	        else 
	        {
	                item->remove_from_user();
	                destruct(item);
	        }
		return 1;
	}	
	if ( sscanf(arg,"%s %s",id,arg1 ) == 2 )
	{
		if( gone_time( me->get_time("use") ) < 1 )    // 时间限制
	        {
//	                me->set_time( "use", time() );
	                return 1;
	        }
	        me->set_time( "use", time() );
	        if (!id) return 1;
	        if (!objectp( item = present(id, me, 1, MAX_CARRY*4) ))
	        {
			if ( !objectp(item=find_any_object(id)) )				   	
	        	// 调用法宝的相应处理函数
			if ( item != me->get_equip(HAND_TYPE) )
			{			
				return 1;
			}	        	
	        }        				     
                if (item->is_record())
                {
                	legend = sprintf("使用 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
                	flag = 1;			
                }		
		arg = arg1;
	        if(     sscanf(arg, "%s.%s", key, arg1) == 2 
	        &&      arg1
	        &&    ( func = item->get_2( "use." + key ) ) )
	        {	        	
	                if( functionp(func) ) evaluate(func, me,arg1);
	                else send_user( me, "%c%s", ':', func );
	        }
	        else if( func = item->get_2( "use." + arg ) ) 
	        {		        	
	                if( functionp(func) ) evaluate(func,me);
	                else send_user( me, "%c%s", ':', func );
	        }	        	
	        if (!item && flag==1) "/sys/user/cmd"->log_item(legend);	
		return 1;	
	}

        if( gone_time( me->get_time("use") ) < 1 )    // 时间限制
        {
//                me->set_time( "use", time() );
                return 1;
        }
        me->set_time( "use", time() );

        if( busy = get_effect(me, EFFECT_CHAR_BUSY) )
        {
                notify( "您还得忙 %d 秒钟。", busy );
                return 1;
        }
        if(     get_effect(me, EFFECT_CHAR_FAINT) 
        ||      get_effect(me, EFFECT_CHAR_FAINT_2)
        ||      get_effect(me, EFFECT_SLEEP)
        ||      get_effect(me, EFFECT_CHAR_DREAM_1)
        ||      get_effect(me, EFFECT_CHAR_DREAM) ) return 1;

        if( get_effect(me, EFFECT_USER_THUNDER) ) PF_FILE_04236->effect_thunder_break(me);    // 雷龙诀(中断)

	if( !arg ) return 1;
        
        if( !objectp( item = present(arg, me, 1, MAX_CARRY*4) ) ) 
	{
		if ( !objectp(item=find_any_object(arg)) )
			return 1;
		if ( item == me->get_equip(FAMILY_TYPE) )
		{			
			item->get_use_effect(me);
		}
        	return 1;
        }

        if( me->get_store( sprintf( "%02d", get_d(item) ) ) )
        {
                notify( item->get_name() + "已经上架，不能使用。" );
                return 1;
        } 
        // 装备道具
        if( item->get_equip_type() && FAMILY_TYPE != item->get_equip_type() ) 
        {
        	if (item->get_bind()==1)
        	{
			result = sprintf("%s一旦装备便马上被绑定，你确定要装备吗？\n"
				ESC "%c\n" ESC "\nuse2 %x#\n"
				, item->get_name(), 1, getoid(item) );
			send_user(me, "%c%c%s", 0x59, 1, result);
                        return 1;
        	}
        	if( get_effect(me, EFFECT_MAGIC_4243) ) return 1;
	        if (me->get_fam_name()=="桃花源" && me->get_perform("03191"))
	        {
	        	notify( "狂暴状态下不能更换装备" );
	        	return 1;
	        }
	        if (me->get_fam_name()=="桃花源" && me->get_perform("03192"))
	        {
	        	notify( "防御状态下不能更换装备" );
	        	return 1;
	        } 
	        if (me->get_fam_name()=="蜀山" && me->get_perform("02221#"))
	        {
	        	notify( "封魔免疫状态下不能更换装备" );
	        	return 1;
	        }	
	        if (me->get_fam_name()=="蜀山" && me->get_perform("02222#"))
	        {
	        	notify( "眩晕免疫状态下不能更换装备" );
	        	return 1;
	        }
        	return me->use_equip(item);
        }
        if (item->is_record())
        {
        	legend = sprintf("使用 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
        	flag = 1;		
        } 
        // 使用道具
        if( !item->is_usable() )
        {
                notify( "不能使用%s。", item->get_name() );
                return 1;
        }
        else if( !item->get_use_effect(me) )
        {
        	if (!item && flag==1) "/sys/user/cmd"->log_item(legend);
                return 1;
        }
        if (flag==1) "/sys/user/cmd"->log_item(legend);
	if (!item) return 1;       
        if( item->is_combined() ) 
                item->add_amount(-1);
        else 
        {
                item->remove_from_user();
                destruct(item);
        }
        return 1;
}
//对宠物使用(食物,物品,装备)
int pet_use(object me,string arg)
{
	int busy,type;
	string id1,id2, legend;
	object pet,item;
	
        if( gone_time( me->get_time("use") ) < 1 )    // 时间限制
        {
                return 1;
        }
        me->set_time( "use", time() );

        if( busy = get_effect(me, EFFECT_CHAR_BUSY) )
        {
                notify( "您还得忙 %d 秒钟。", busy );
                return 1;
        }
        if(     get_effect(me, EFFECT_CHAR_FAINT) 
        ||      get_effect(me, EFFECT_CHAR_FAINT_2)
        ||      get_effect(me, EFFECT_SLEEP)
        ||      get_effect(me, EFFECT_CHAR_DREAM_1)
        ||      get_effect(me, EFFECT_CHAR_DREAM) ) return 1;

        if( get_effect(me, EFFECT_USER_THUNDER) ) PF_FILE_04236->effect_thunder_break(me);    // 雷龙诀(中断)

	if ( sscanf(arg,"%s pet %s",id1,id2) != 2 )
		return 1;
	pet = find_char(id2);
	if ( !pet )
		return 1;	
	if ( !pet->is_pet() || pet->get_owner() != me )
		return 1;
	if ( !objectp(item=find_any_object(id1)) )
			return 1;	

        if( me->get_store( sprintf( "%02d", get_d(item) ) ) )
        {
                notify( item->get_name() + "已经上架，不能使用。" );
                return 1;
        }	
	type = item->get_item_type_2();
	if ( type == ITEM_TYPE_2_PET || type == ITEM_TYPE_2_CON_MP || type == ITEM_TYPE_2_CON_HP || type == ITEM_TYPE_2_CON_HP || type == ITEM_TYPE_2_CON_ALL )
	{
		if( !item->get_use_effect(pet) )
	        {
	                return 1;
	        }
                if (item->is_record())
                {
                	legend = sprintf("使用 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
			"/sys/user/cmd"->log_item(legend);
                }	        
	        if( item->is_combined() ) 
	                item->add_amount(-1);
	        else 
	        {
	                item->remove_from_user();
	                destruct(item);
	        }
	        return 1;
	}
	notify("不能对宠物使用！");
}