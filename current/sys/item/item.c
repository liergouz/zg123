
#include <ansi.h>
#include <item.h>
#include <equip.h>

// 函数：生成二进制码
void SAVE_BINARY() { }

// 函数：获取道具描述(基本)
string get_desc_string( object who, object item )
{
        switch( item->get_equip_type() )
        {
       case HEAD_TYPE : return sprintf( "［帽子］%s\n", item->get_desc() );
       case NECK_TYPE : return sprintf( "［饰物］%s\n", item->get_desc() );
     case WEAPON_TYPE : return sprintf( "［武器］%s\n", item->get_desc() );
      case ARMOR_TYPE : if( item->get_gender() == 1 )
                                return sprintf( "［衣服］%s\n", item->get_desc() );    // "［防具］"
                        else    return sprintf( "［衣服］%s\n", item->get_desc() );    // "［防具］"
      case WAIST_TYPE : return sprintf( "［腰带］%s\n", item->get_desc() );
      case BOOTS_TYPE : return sprintf( "［鞋子］%s\n", item->get_desc() );
       case HAND_TYPE : return sprintf( "[法宝]%s\n", item->get_desc() );    // "［法宝］"       
              default : 
              		if( item->is_usable() )
                                return sprintf( "［可使用］%s\n", item->get_desc() );
                        else    return sprintf( "%s\n", item->get_desc() );
        }
}

string get_pawn_string(object me, string prop)
{
	string name, result="", name2, *key, id, color, special;
	int level, point, i, size, use, maxuse, locktime, lockutil, z, x, y;
	object map;
			if( !sscanf( prop, "%s;%*s", name ) || !load_object(name) ) return "";

			result = "";
			switch(	name->get_item_type() )
			{
	 case ITEM_TYPE_EQUIP :	if( sscanf( prop, "%s;%d;%d;%d;%s;[%s]%d,%d", name, size, use, maxuse, prop, id, locktime, lockutil ) != 8 )
				{
					return "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。";
				}
				if( !sscanf(prop, "%s-1-:%d,%*s", name2, point)	) point	= 0;	// 免装备等级
				level =	name->get_level() - me->get_equip_less_level() - point;
				if( level < 0 )	level =	0;
					
				switch(	name->get_item_color() )
				{
			      default :	color =	"";  break;
			       case 1 :	color =	HIC;  break;
			       case 2 :	color =	HIY;  break;
			       case 3 :	color =	HIG;  break;
			       case 4 :	color =	HIC;  break;
				}
							
				if( prop != "" )
				{				
					key = explode(prop, ",");
					size = sizeof(key);
					for( i = 0;i < size; i ++ )
					{
						if( !sscanf( key[i], "%s:%s", name2, special ) )	continue;
						if (name2=="forge"&&(z=strlen(special)))
						{
							result += color;
							for(x=0;x<z;x++)
								result += "★";	
							result += "\n";				
							break;
						}
					}
				}				
				
				if (name->get_stuff_type()==0)
					result += sprintf( "耐久度: %d / %d\n",	use / 100, maxuse / 100	);
				else
					result += sprintf( "使用次数: %d / %d\n", use /	100, maxuse / 100 );
				if (name->get_stuff_type()==0)
				{
					if (level>0) result += sprintf(	"装备要求: %s%d	级\n", level > me->get_level() ? HIR : NOR,  name->get_level() );
				}
				else
				{
					if (level>0) result += sprintf(	"技能要求: %s%d	级\n", NOR,  name->get_level() );
				}

				name2 =	me->get_fam_name();

				switch(	name->get_equip_type() )
				{
			       case HEAD_TYPE :
			       case ARMOR_TYPE :
						if( name->get_gender() == 1 )
							result += sprintf( "适用于: %s男性\n", me->get_gender()	== 1 ? NOR : HIR );
						else
						if( name->get_gender() == 2 )
							result += sprintf( "适用于: %s女性\n", me->get_gender()	== 2 ? NOR : HIR );
						// break;    //	同下面共用，不能有 break;

				      default :	switch(	name->get_family() )
						{
//						default	: result += "适用门派: －－\n";	 break;
					       case 1 :	result += sprintf( "适用门派: %s桃花源\n",
								name2 != "桃花源" ? HIR	: NOR );  break;
					       case 2 :	result += sprintf( "适用门派: %s蜀山\n",
								name2 != "蜀山"	? HIR :	NOR );	break;
					       case 3 :	result += sprintf( "适用门派: %s禁卫军\n",
								name2 != "禁卫军" ? HIR	: NOR );  break;
					       case 4 :	result += sprintf( "适用门派: %s唐门\n",
								name2 != "唐门"	? HIR :	NOR );	break;
					       case 5 :	result += sprintf( "适用门派: %s茅山\n",
								name2 != "茅山"	? HIR :	NOR );	break;
					       case 6 :	result += sprintf( "适用门派: %s昆仑山\n",
								name2 != "昆仑山" ? HIR	: NOR );  break;
					       case 7 :	result += sprintf( "适用门派: %s云梦泽\n",
								name2 != "云梦泽" ? HIR	: NOR );  break;
						}
						break;
			     case WEAPON_TYPE :	switch(	name->get_family() )
						{
//						default	: result += "适用门派: －－\n";	 break;
					       case 1 :	result += sprintf( "适用门派: %s桃花源\n",
								name2 != "桃花源" ? HIR	: NOR );  break;
					       case 2 :	result += sprintf( "适用门派: %s蜀山\n",
								name2 != "蜀山"	? HIR :	NOR );	break;
					       case 3 :	result += sprintf( "适用门派: %s禁卫军\n",
								name2 != "禁卫军" ? HIR	: NOR );  break;
					       case 4 :	result += sprintf( "适用门派: %s唐门\n",
								name2 != "唐门"	? HIR :	NOR );	break;
					       case 5 :	result += sprintf( "适用门派: %s茅山\n",
								name2 != "茅山"	? HIR :	NOR );	break;
					       case 6 :	result += sprintf( "适用门派: %s昆仑山\n",
								name2 != "昆仑山" ? HIR	: NOR );  break;
					       case 7 :	result += sprintf( "适用门派: %s云梦泽\n",
								name2 != "云梦泽" ? HIR	: NOR );  break;
					       case 9 :	result += sprintf( "适用门派: %s云梦泽、蜀山、茅山、昆仑山\n",
								(name2 != "云梦泽" && name2 != "茅山" && name2 != "蜀山" && name2 != "昆仑山" ) ? HIR	: NOR );  break;
						}
						break;
				}

				if( prop != "" )
				{				
					key = explode(prop, ",");
					size = sizeof(key);
					for( i = 0;i < size; i ++ )
					{
						if( !sscanf( key[i], "%s:%d", name2, point ) )	continue;
						if (name2=="hide"&&point>0)
						{
							size = -1;
							id = "";
							result += HIR "未鉴定";
							break;
						}
					}
					if (size==-1) break;
					for( i = 0;i < size; i ++ )
					{
						if( !sscanf( key[i], "|%s:%d", name2, point ) )	continue;
						result += ITEM_EQUIP_D->get_chinese_prop_string_3(name,	name2, point, color);
					}
					if( !sscanf(prop, "%s+:%d,%*s",	name2, point) )	point =	0;
				}


				id = "";  if( point ) id = sprintf("%+d", point);

				break;

      case ITEM_TYPE_TALISMAN :	if( sscanf( prop, "%s;%d;%d;%d;%d;[%s]%d,%d", name, size, use, maxuse, point, id, locktime, lockutil ) != 8 )
				{
					return "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。";
				}

				result += sprintf( "耐久度: %d / %d\n",	use / 100, maxuse / 100	);
				if (name->get_stuff_type()==0) result += sprintf( "%d 级法宝\n", name->get_level() );
				else result += sprintf( "装备要求 %d 级\n", name->get_level() );

				switch(	name->get_talisman_type() )
				{
			      default :	break;

			       case 2 :	// 九龙神火罩
					result += sprintf( "气血: %d / %d\n", point, name->get_max_hp()	);
					break;
			       case 9 :	// 招魂幡
					if( point < name->get_time_interval() )
						result += sprintf( HIR "%d％ 准备中\n",	point *	100 / name->get_time_interval()	);
					else	result += HIG "100％ 准备好\n";
					break;
				}

				switch(	name->get_level() )
				{
			      default :	color =	"";  break;
			       case 2 :	color =	HIC;  break;
			       case 3 :	color =	HIY;  break;
				}
				id = "";

				break;

	  case ITEM_TYPE_FLAG :	if( sscanf( prop, "%s;%d;[%s]%d,%d", name, size, id, locktime, lockutil	) != 5 )
				{
					return "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。";
				}

				name2 =	me->get_fam_name();
				result += sprintf( "适用门派: %s云梦泽\n", name2 != "云梦泽" ? HIR : NOR );

				color =	"";  id	= "";

				break;

      case ITEM_TYPE_POISON   :	if( sscanf( prop, "%s;%d;[%s]%d,%d", name, size, id, locktime, lockutil	) != 5 )
				{
					return "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。";
				}

				name2 =	me->get_fam_name();
//				result += sprintf( "适用门派: %s唐门\n", name2 != "唐门" ? HIR : NOR );

				if( point = name->get_poison() ) result	+= ITEM_EQUIP_D->get_chinese_prop_string(name,	 "@" , point);

				color =	"";  id	= "";

				break;

      case ITEM_TYPE_POISON_2 :	if( sscanf( prop, "%s;%d;%d;[%s]%d,%d",	name, size, point, id, locktime, lockutil ) != 6 )
				{
					return "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。";
				}
				result += sprintf( "毒性: %d\n", point );

				color =	"";  id	= "";

				break;

	case ITEM_TYPE_BOOK   :
	case ITEM_TYPE_BOOK_2 :	if( sscanf( prop, "%s;%d;[%s]%d,%d", name, size, id, locktime, lockutil	) != 5 )
				{
					return "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。";
				}
				name2 = name->get_family_name();
				if( name2 != " －" && name2!="" && name2!=0 )
				       result += sprintf( "适用门派: %s%s\n", name2[1..<1] != me->get_fam_name() ? HIR : NOR, name2[1..<1]	);

				color =	"";  id	= "";

				break;

      case ITEM_TYPE_TREASURE :	if( sscanf( prop, "%s;%d;%d;%d;%d;[%s]%d,%d", name, size, z, x,	y, id, locktime, lockutil ) != 8 )
				{
					return "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。";
				}
				if( map	= get_map_object(z) ) result +=	sprintf( "位置:	%s(%d,%d)\n", map->get_name(), x, y );

				color =	"";  id	= "";

				break;

     case ITEM_TYPE_DIAMOND_2 :	if( sscanf( prop, "%s;%d;%d;[%s]%d,%d",	name, size, point, id, locktime, lockutil ) != 6 )
				{
					return "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。";
				}
				color =	"";  id	= "";  if( point ) id =	sprintf("%+d", point);

				break;

     case ITEM_TYPE_POTENTIAL :	if( sscanf( prop, "%s;%d;%d;[%s]%d,%d",	name, size, point, id, locktime, lockutil ) != 6 )
				{
					return "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。";
				}
				if( point ) result += sprintf( "潜能: %+d\n", point );

				color =	"";  id	= "";

				break;
	case ITEM_TYPE_SPECIAL :if( sscanf( prop, "%s;%d;%s;[%s]%d,%d", name, size, special,id, locktime, lockutil	) != 6 )
				{
					return "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。";
				}
				color =	"";  id	= "";
//				result = name->get_special_desc(special);
				return sprintf( "%s%s%s\n%s%s", color, name->get_name(), id, name->get_special_desc(special), result );
		      default :	if( sscanf( prop, "%s;%d;[%s]%d,%d", name, size, id, locktime, lockutil	) != 5 )
				{
					return "数据出了问题的物品，赎回会导致物品消失。有问题请通知ＧＭ。";
				}
				color =	"";  id	= "";

				break;
			}
			if ( name->is_suit() )
				result += name->get_suit_desc();
	result = sprintf( "%s%s%s\n%s%s", color, name->get_name(), id, ITEM_ITEM_D->get_desc_string(me, name), result )	;			
	return result;				
	
}

// 函数：获取道具描述(所有)
// 说明：flag == 1 不显示卖出价
varargs string get_look_string( object who, object item, int flag )
{
        object map, fileobj;
        string name, file, color, result, product, bind,forge;
        int level, point;  
        int i,size;      
	bind = "";
	switch(item->get_bind())
	{
	case 1:
		if (item->get_equip_type())
			bind = HIC"（装备后绑定）"NOR;
		else
			bind = HIC"（使用后绑定）"NOR;
		break;
	case 2:
		if (item->get_equip_type())
			bind = HIC"（装备已绑定）"NOR;
		else
			bind = HIC"（使用已绑定）"NOR;
		break;	
	case 3:
		bind = HIC"（拾取绑定）"NOR;
		break;

	case 4:
		bind = HIC"（拾取已绑定）"NOR;
		break;
	}
        if( !is_player(who) )
                result = sprintf( "%s%s[%s]%s%x#%s\n%s", item->get_name(), item->get_item_make_desc(), 
                        item->get_user_id(), item->is_locked()>0 ? "[锁]" : "", getoid(item), bind, get_desc_string(who, item) );
        else    result = sprintf( "%s%s%s\n%s", item->get_name(), item->get_item_make_desc(), bind, get_desc_string(who, item) );
	if (item->get_product_id()!="" &&  item->get_product_id()!=0 ) 
	{
        	switch( item->get_item_color() )
        	{
	        default : color = HIC;  break;
	         case 1 : color = HIY;  break;
	         case 2 : color = HIR;  break;
	         case 3 : color = PPM;  break;
	        }
		result += sprintf("%s制作者：%s\n", color, item->get_product_id());	
	}
	color = "";
        switch( item->get_item_color() )
        {
        default : color = "";  break;
	 case 1 : color = HIC;  break;
         case 2 : color = HIY;  break;
	 case 3 : color = PPM;  break;
        }
        forge = item->get("forge");
	if ( size=strlen(forge) )
	{
        	result += color;
	        for(i=0;i<size;i++)
	        	result += "★";
        	result += NOR"\n";
	}
        switch( item->get_item_type() )
        {
                      default : break;

         case ITEM_TYPE_EQUIP :
         			level = item->get_level() - who->get_equip_less_level() - item->get("-1-");    // 免装备等级
                                if( level < 0 ) level = 0;

                                if (item->get_stuff_type()==0)
                                {
                                	if (level>0) result += sprintf( "装备要求: %s%d 级\n", level > who->get_level() ? HIR : NOR, item->get_level() );
                                }
                                else
                                {
                                	if (level>0) result += sprintf( "技能要求: %s%d 级\n", NOR, item->get_level() );
                                }
                                name = who->get_fam_name();
                                switch( item->get_equip_type() )
                                {
                               case HEAD_TYPE :
                               case ARMOR_TYPE :
                                                if( item->get_gender() == 1 )
                                                        result += sprintf( "适用于: %s男性\n", who->get_gender() == 1 ? NOR : HIR );
                                                else
                                                if( item->get_gender() == 2 )
                                                	result += sprintf( "适用于: %s女性\n", who->get_gender() == 2 ? NOR : HIR );
                                               	
                                                // break;    // 同下面共用，不能有 break;

                                      default : switch( item->get_family() )
                                                {
//                                              default : result += "适用门派: －－\n";  break;
                                               case 1 : result += sprintf( "适用门派: %s桃花源\n",
                                                                name != "桃花源" ? HIR : NOR );  break;
                                               case 2 : result += sprintf( "适用门派: %s蜀山\n",
                                                                name != "蜀山" ? HIR : NOR );  break;
                                               case 3 : result += sprintf( "适用门派: %s禁卫军\n",
                                                                name != "禁卫军" ? HIR : NOR );  break;
                                               case 4 : result += sprintf( "适用门派: %s唐门\n",
                                                                name != "唐门" ? HIR : NOR );  break;
                                               case 5 : result += sprintf( "适用门派: %s茅山\n",
                                                                name != "茅山" ? HIR : NOR );  break;
                                               case 6 : result += sprintf( "适用门派: %s昆仑山\n",
                                                                name != "昆仑山" ? HIR : NOR );  break;
                                               case 7 : result += sprintf( "适用门派: %s云梦泽\n",
                                                                name != "云梦泽" ? HIR : NOR );  break;
                                                }
                                                break;

                             case WEAPON_TYPE : switch( item->get_family() )
                                                {
//                                              default : result += "适用门派: －－\n";  break;
                                               case 1 : result += sprintf( "适用门派: %s桃花源\n",
                                                                name != "桃花源" ? HIR : NOR );  break;
                                               case 2 : result += sprintf( "适用门派: %s蜀山\n",
                                                                name != "蜀山" ? HIR : NOR );  break;
                                               case 3 : result += sprintf( "适用门派: %s禁卫军\n",
                                                                name != "禁卫军" ? HIR : NOR );  break;
                                               case 4 : result += sprintf( "适用门派: %s唐门\n",
                                                                name != "唐门" ? HIR : NOR );  break;
                                               case 5 : result += sprintf( "适用门派: %s茅山\n",
                                                                name != "茅山" ? HIR : NOR );  break;
                                               case 6 : result += sprintf( "适用门派: %s昆仑山\n",
                                                                name != "昆仑山" ? HIR : NOR );  break;
                                               case 7 : result += sprintf( "适用门派: %s云梦泽\n",
                                                                name != "云梦泽" ? HIR : NOR );  break;
						case 9 :	result += sprintf( "适用门派: %s云梦泽、蜀山、茅山、昆仑山\n",
								(name != "云梦泽" && name != "茅山" && name != "蜀山" && name != "昆仑山" ) ? HIR	: NOR );  break;
                                                }
                                                if (item->get_poison() && time() > item->get("poison_time") ) result += sprintf( "毒性：%d\n", item->get_poison());
                                                break;
                                }
		         	if ( item->get_level()>=30 && item->get_hide()&&clonep(item))
		         	{
		         		result += HIR "未鉴定\n";
		         		break;
		         	} 
				if (item->get_stuff_type()==0 && item->get_max_lasting()>0)
                                	result += sprintf( "耐久度: %d / %d\n", item->get_lasting() / 100, item->get_max_lasting() / 100 );
                                else
                                if (item->get_max_lasting()>0)
                                	result += sprintf( "使用次数: %d / %d\n", item->get_lasting() / 100, item->get_max_lasting() / 100 );		         	
                                file = get_file_name(item);

                                if( point = item->get( "ap" )  + item->get( "ap+" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "ap" , point, color);
                                if( point = item->get( "app" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "app" , point, color);
                                if( point = item->get( "ap2" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "ap2" , point, color);
                                if( point = item->get( "double" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "double" , point, color);
                                if( point = item->get( "double2" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "double2" , point, color);
                                if( point = item->get( "ap%" ) + item->get( "ap%+" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "ap%", point, color);
                                if( point = item->get(  "!%")  + item->get(  "!%+") )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,   "!%", point, color);
                                if( point = item->get( "cp" )  + item->get( "cp+" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "cp" , point, color);
                                if( point = item->get( "cpp" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "cpp" , point, color);
                                if( point = item->get( "cp2" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "cp2" , point, color);
                                if( point = item->get( "cp%" ) + item->get( "cp%+" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "cp%", point, color);
                                if( point = item->get( "c!%")  + item->get( "c!%+") )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "c!%", point, color);
                                if( point = item->get( "t!%")  + item->get( "t!%+") )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "t!%", point, color);
                                if( point = item->get( "dp" )  + item->get( "dp+" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "dp" , point, color);
                                if( point = item->get( "dpp" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "dpp" , point, color);
                                if( point = item->get( "dp2" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "dp2" , point, color);
                                if( point = item->get( "pp" )  + item->get( "pp+" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "pp" , point, color);
                                if( point = item->get( "ppp" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "ppp" , point, color);
                                if( point = item->get( "pp2" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "pp2" , point, color);
                                if( point = item->get( "hp" )  + item->get( "hp+" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "hp" , point, color);
                                if( point = item->get( "hpp" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "hpp" , point, color);
                                if( point = item->get( "hp2" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "hp2" , point, color);
                                if( point = item->get( "hp%" ) + item->get( "hp%+" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "hp%", point, color);
                                if( point = item->get( "mp" )  + item->get( "mp+" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "mp" , point, color);
                                if( point = item->get( "mpp" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "mpp" , point, color);
                                if( point = item->get( "mp2" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "mp2" , point, color);
                                if( point = item->get( "mp%" ) + item->get( "mp%+" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "mp%", point, color);
                                if( point = item->get( "hp*" ) + item->get( "hp*+" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "hp*", point, color);
                                if( point = item->get( "mp*" ) + item->get( "mp*+" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "mp*", point, color);
                                if( point = item->get( "sp" )  + item->get( "sp+" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "sp" , point, color);
                                if( point = item->get( "sp2" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "sp2" , point, color);
                                if( point = item->get(  "?%")  + item->get(  "?%+") )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,   "?%", point, color);
                                if( point = item->get( "c?%")  + item->get( "c?%+") )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "c?%", point, color);
                                if( point = item->get( "-*" )  + item->get( "-*+" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "-*" , point, color);
                                if( point = item->get( "-*%" ) + item->get( "-*%+" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "-*%", point, color);
                                if( point = item->get("-c*" )  + item->get("-c*+" ) )  result += ITEM_EQUIP_D->get_chinese_prop_string_3(file, "-c*" , point, color);
                                if( point = item->get("-c*%" ) + item->get("-c*%+" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file, "-c*%", point, color);
                                                      if( point = item->get_poison() ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,   "@" , point, color);
                                if( point = item->get(  "@%" ) + item->get(  "@%+" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,   "@%", point, color);
                                if( point = item->get( "X@%" ) + item->get( "X@%+" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "X@%", point, color);
                                if( point = item->get( "-@%" ) + item->get( "-@%+" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "-@%", point, color);
                                if( point = item->get(  "/%" ) + item->get(  "/%+" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,   "/%", point, color);
                                if( point = item->get( "??%" ) + item->get( "??%+" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,  "??%", point, color);
                                if( point = item->get(  "#%" ) + item->get(  "#%+" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,   "#%", point, color);
				if( point = item->get(  "hp+@" )) result += sprintf("每5秒回%d点气血\n",point);
				if( point = item->get(  "mp+@" )) result += sprintf("每5秒回%d点法力\n",point);
				if( point = item->get(  "cp+@" )) result += sprintf("增加法术所造成的伤害效果%d点\n",point);
				if( point = item->get(  "heal+@" )) result += sprintf("增加法术所造成的治疗效果%d点\n",point);
                                break;

      case ITEM_TYPE_TALISMAN : 
      				level = item->get_level();
      				if (item->get_stuff_type()==0)
      				{
	      				switch( level )
	                                {
	                               case 1 : color = HIC;  break;
	                               case 2 : color = HIY;  break;
	                              default : color = PPM;  break;
	                        	}
	                        }
	                        else
	                        {
	                        	switch(item->get_item_color())
	                                {
	                               case 0 : color = "";  break;
	                               case 1 : color = HIC;  break;
	                               case 3 : color = PPM;  break;
	                              default : color = HIY;  break;
	                        	}	                        	
				}
				if (!item->is_limit_time_item())
                                	result += sprintf( "耐久度: %d / %d\n", item->get_lasting() / 100, item->get_max_lasting() / 100 );
                                if (item->get_stuff_type()==0) result += sprintf( "%d 级法宝\n", level );
                                else result += sprintf( "技能要求 %d 级\n", level );

                                switch( item->get_talisman_type() )
                                {
                              default : break;

                               case 2 : // 九龙神火罩
                                        result += sprintf( "气血: %d / %d\n", item->get_hp(), item->get_max_hp() );
                                        break;
                               case 9 : // 招魂幡
                                        if( ( point = item->get_heart_sec() ) < item->get_time_interval() )
                                                result += sprintf( HIR "%d％ 准备中\n", point * 100 / item->get_time_interval() );
                                        else    result += HIG "100％ 准备好\n";
                                        break;
                                }

                                if( point = item->get( "ap" )  ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "ap" , point);
                                if( point = item->get( "ap%" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "ap%", point);
                                if( point = item->get(  "!%")  ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,   "!%", point);
                                if( point = item->get( "cp" )  ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "cp" , point);
                                if( point = item->get( "cp%" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "cp%", point);
                                if( point = item->get( "c!%")  ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "c!%", point);
                                if( point = item->get( "t!%")  ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "t!%", point);
                                if( point = item->get( "dp" )  ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "dp" , point);
                                if( point = item->get( "pp" )  ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "pp" , point);
                                if( point = item->get( "hp" )  ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "hp" , point);
                                if( point = item->get( "hp%" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "hp%", point);
                                if( point = item->get( "mp" )  ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "mp" , point);
                                if( point = item->get( "mp%" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "mp%", point);
                                if( point = item->get( "hp*" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "hp*", point);
                                if( point = item->get( "mp*" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "mp*", point);
                                if( point = item->get( "sp" )  ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "sp" , point);
                                if( point = item->get(  "?%")  ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,   "?%", point);
                                if( point = item->get( "c?%")  ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "c?%", point);
                                if( point = item->get( "-*" )  ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "-*" , point);
                                if( point = item->get( "-*%" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "-*%", point);
                                if( point = item->get("-c*" )  ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color, "-c*" , point);
                                if( point = item->get("-c*%" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color, "-c*%", point);
//                              if( point = item->get_poison() ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,   "@" , point);
                                if( point = item->get(  "@%" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,   "@%", point);
                                if( point = item->get( "X@%" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "X@%", point);
                                if( point = item->get( "-@%" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "-@%", point);
                                if( point = item->get(  "/%" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,   "/%", point);
                                if( point = item->get( "??%" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,  "??%", point);
                                if( point = item->get(  "#%" ) ) result += ITEM_EQUIP_D->get_chinese_prop_string_2(color,   "#%", point);

                                break;

          case ITEM_TYPE_FLAG : name = who->get_fam_name();
                                result += sprintf( "适用门派: %s云梦泽\n", name != "云梦泽" ? HIR : NOR );

                                color = "";  break;

      case ITEM_TYPE_POISON   : name = who->get_fam_name();
//                                result += sprintf( "适用门派: %s唐门\n", name != "唐门" ? HIR : NOR );

                                file = get_file_name(item);
                                if( point = item->get_poison() ) result += ITEM_EQUIP_D->get_chinese_prop_string_3(file,   "@" , point);

                                color = "";  break;

      case ITEM_TYPE_POISON_2 : if( point = item->get_poison() ) result += sprintf("毒性: %d\n", point);

                                color = "";  break;

        case ITEM_TYPE_BOOK   :
        case ITEM_TYPE_BOOK_2 : 
        			name = item->get_family_name();
        			if( name != " －" && name!=""  && name!=0)
                                        result += sprintf( "适用门派: %s%s\n", name[1..<1] != who->get_fam_name() ? HIR : NOR, name[1..<1] );

                                break;

      case ITEM_TYPE_FLY_SEAL : switch( who->get_latest_city() / 100 )
                                {
                              case 10 : result += "返回：齐国\n";  break;
                              case 20 : result += "返回：韩国\n";  break;
                              case 30 : result += "返回：赵国\n";  break;
                              case 40 : result += "返回：魏国\n";  break;
                              case 50 : result += "返回：秦国\n";  break;
                              case 60 : result += "返回：楚国\n";  break;
                              case 70 : result += "返回：燕国\n";  break;
                              case 80 : result += "返回：周国\n";  break;
                              default : result += "返回：新手村\n";  break;
                                }

                                color = "";  break;

          case ITEM_TYPE_GOOD : if( point = item->get_buyin() ) result += sprintf("买入价: %d\n", point);

                                color = "";  break;

        case ITEM_TYPE_CHEQUE2 :
        			if( point = item->get_orgin_money() )
                                        result += sprintf("商票本金: %d\n流动资金: %d\n当流动资金达到一定数目时，交还商票给门派的司库即可完成筹集资金任务。", point, item->get_money() );
                                color = "";  break;        
        case ITEM_TYPE_CHEQUE: 
        			if( point = item->get_orgin_money() )
                                        result += sprintf("商票本金: %d\n流动资金: %d\n当流动资金达到%d时，交还商票给帮派的帐房先生即可完成经商任务。", point, item->get_money(), point * 3 /2 );
                                color = "";  break;

      case ITEM_TYPE_TREASURE : if( objectp( map = get_map_object( item->get_map_z() ) ) )
      				{
      					if(item->get_name()=="挖宝小锄头")
      						
						result += sprintf( "在"HIR"%s国的（%d，%d）"NOR"似乎隐藏着什么宝物。\n", map->get_name(), item->get_map_x(), item->get_map_y() );
     					else
						result += sprintf( "位置: %s(%d,%d)\n", map->get_name(), item->get_map_x(), item->get_map_y() );
				}
                                break;

     case ITEM_TYPE_POTENTIAL : if( point = item->get_potential() ) result += sprintf("潜能: %+d\n", point);

                                color = "";  break;
	case ITEM_TYPE_SPECIAL :
				break;
        }
        if( !flag && ( point = item->get_value() ) > 0 )
        {
                if( !( level = item->get_max_lasting() ) ) point = point / 2;
                else point = point / 2 * ( item->get_lasting() * 100 / level ) / 100;    // 小心越界
                result += sprintf("卖出价: %d\n", point );
        }
        if (item->get_item_type_2()==ITEM_TYPE_2_PRODUCT)
        {
        	fileobj = load_object(sprintf("/skill/06/%04d", item->get_product_skill()));
        	if (fileobj) 
        	{
        		if (who->get_skill(item->get_product_skill()))
        			result += sprintf("要求技能：%s\n", fileobj->get_name());
        		else
        			result += sprintf(HIR"要求技能：%s\n", fileobj->get_name());
        	}
        	if (who->get_skill(item->get_product_skill())<item->get_product_level())
        		result += sprintf(HIR"要求技能等级：%d\n", item->get_product_level());
        	else
        		result += sprintf("要求技能等级：%d\n", item->get_product_level());
        	if ("/sys/item/product" ->check_vita_skill(who, item->get_product_type()+item->get_product_skill()*100)==1)
        		result += HIC"已学习";
        	product = item->get_product();
        	if (strlen(product)<6)
        		fileobj = load_object(sprintf("/item/stuff/%04d", to_int(product)));
        	else
        		fileobj = load_object(item->get_product());
        	if (fileobj) 
        	{
        		if (item->get_item_color() == 2) result += sprintf("\n" HIY "成品：%s\n", fileobj->get_name());
        		else if (item->get_item_color() == 1) result += sprintf("\n" HIC "成品：%s\n", fileobj->get_name());
        		else result += sprintf("\n成品：%s\n", fileobj->get_name());
        		result += sprintf("%s\n", "/sys/item/item"->get_look_string(who, fileobj, 0));
        	}
        }
        if ( item->is_suit() )
        	result += "sys/user/suit"->get_suit_desc(who,item)+"\n";
        if ( item->get_equip_type() == FAMILY_TYPE )
        	result += item->get_family_desc();
        switch( item->get_item_color() )
        {
        default : color = "";  break;
	 case 1 : color = HIC;  break;
         case 2 : color = HIY;  break;
	 case 3 : color = PPM;  break;
	 case 4 : color = HIG;  break;
        }
        if ( stringp(file=item->get_tail_desc()) )
        	result += file+"\n";        	
        return color + result;
}

string get_prop_string(object item)
{
        string id, file, prop;
        int amount, index, point, locktime, lockutil;
        int i, size;	
        file = get_file_name(item);
        amount = item->get_amount();
        index = get_d(item);

        if( !stringp( id = item->get_user_id() ) ) id = "-";
        locktime = item->get_lock_time();
        lockutil = item->get_lock_until();

                switch( item->get_item_type() )
                {
         case ITEM_TYPE_EQUIP : prop = sprintf( "%s;%d;%d;%d;%d;%s;[%s]%d,%d", 
                                        file, amount, index, item->get_lasting(), item->get_max_lasting(), ITEM_EQUIP_D->get_save_prop_string(item), id, locktime, lockutil ) ;
                                break;

      case ITEM_TYPE_TALISMAN : switch( item->get_talisman_type() )
                                {
                              default : point = 0;  break;
                               case 2 : point = item->get_hp();  break;    // 九龙神火罩
                               case 9 : point = item->get_heart_sec();  break;    // 招魂幡
                                }
                                prop = sprintf( "%s;%d;%d;%d;%d;%d;[%s]%d,%d", 
                                        file, amount, index, item->get_lasting(), item->get_max_lasting(), point, id, locktime, lockutil );
                                break;

      case ITEM_TYPE_POISON_2 : prop = sprintf( "%s;%d;%d;%d;[%s]%d,%d", 
                                        file, amount, index, item->get_poison(), id, locktime, lockutil ) ;
                                break;

          case ITEM_TYPE_GOOD : prop = sprintf( "%s;%d;%d;%d;[%s]%d,%d", 
                                        file, amount, index, item->get_buyin(), id, locktime, lockutil ) ;
                                break;
       case ITEM_TYPE_CHEQUE2 :
        case ITEM_TYPE_CHEQUE : prop = sprintf( "%s;%d;%d;%d;%d;[%s]%d,%d", 
                                        file, amount, index, item->get_orgin_money(), item->get_money(), id, locktime, lockutil ) ;
                                break;

      case ITEM_TYPE_TREASURE : prop = sprintf( "%s;%d;%d;%d;%d;%d;[%s]%d,%d", 
                                        file, amount, index, item->get_map_z(), item->get_map_x(), item->get_map_y(), id, locktime, lockutil );
                                break;

     case ITEM_TYPE_DIAMOND_2 : prop = sprintf( "%s;%d;%d;%d;[%s]%d,%d", 
                                        file, amount, index, item->get_item_level(), id, locktime, lockutil );
                                break;

     case ITEM_TYPE_POTENTIAL : prop = sprintf( "%s;%d;%d;%d;[%s]%d,%d", 
                                        file, amount, index, item->get_potential(), id, locktime, lockutil ) ;
                                break;
       case ITEM_TYPE_SPECIAL :
     				prop = sprintf( "%s;%d;%d;%s;[%s]%d,%d", file, amount, index,item->get("special"), id, locktime, lockutil ) ;
     				break;
     case ITEM_TYPE_DIAMOND_3 : 
     				prop = sprintf( "%s;%d;%d;%s;[%s]%d,%d", file, item->get_level(), index,item->get("special"), id, locktime, lockutil ) ;
     				break;    			
                      default : prop = sprintf( "%s;%d;%d;[%s]%d,%d", file, amount, index, id, locktime, lockutil ) ;
                                break;
                }
	return prop;                
}

string get_pawn_save_string(object item)
{
	string file, total, prop, id;
	int amount, locktime, lockutil, point;
                file = get_file_name(item);
                amount = item->get_amount();
                if (!load_object(file))
                {
                	return "";
                }
                if( !stringp( id = item->get_user_id() ) ) id = "-";
                locktime = item->get_lock_time();
                lockutil = item->get_lock_until();

                switch( item->get_item_type() )
                {
         case ITEM_TYPE_EQUIP : prop = sprintf( "%s;%d;%d;%d;%s;[%s]%d,%d",
                                        file, amount, item->get_lasting(), item->get_max_lasting(), ITEM_EQUIP_D->get_save_prop_string_2(item), id, locktime, lockutil );
                                break;

      case ITEM_TYPE_TALISMAN : switch( item->get_talisman_type() )
                                {
                              default : point = 0;  break;
                               case 2 : point = item->get_hp();  break;    // 九龙神火罩
                               case 9 : point = item->get_heart_sec();  break;    // 招魂幡
                                }
                                prop = sprintf( "%s;%d;%d;%d;%d;[%s]%d,%d",
                                        file, amount, item->get_lasting(), item->get_max_lasting(), point, id, locktime, lockutil );
                                break;

      case ITEM_TYPE_POISON_2 : prop = sprintf( "%s;%d;%d;[%s]%d,%d",
                                        file, amount, item->get_poison(), id, locktime, lockutil );
                                break;

      case ITEM_TYPE_TREASURE : prop = sprintf( "%s;%d;%d;%d;%d;[%s]%d,%d",
                                        file, amount, item->get_map_z(), item->get_map_x(), item->get_map_y(), id, locktime, lockutil );
                                break;

     case ITEM_TYPE_DIAMOND_2 : prop = sprintf( "%s;%d;%d;[%s]%d,%d",
                                        file, amount, item->get_item_level(), id, locktime, lockutil );
                                break;

     case ITEM_TYPE_POTENTIAL : prop = sprintf( "%s;%d;%d;[%s]%d,%d",
                                        file, amount, item->get_potential(), id, locktime, lockutil );
                                break;
	case ITEM_TYPE_SPECIAL : prop = sprintf( "%s;%d;%s;[%s]%d,%d", file, amount,item->get("special"),id, locktime, lockutil );
                                break;
        case ITEM_TYPE_DIAMOND_3:
        			prop = sprintf( "%s;%d;[%s]%d,%d", file, item->get_level(), id, locktime, lockutil );
                                break;
                      default : prop = sprintf( "%s;%d;[%s]%d,%d", file, amount, id, locktime, lockutil );
                                break;
                }
	return prop;
}