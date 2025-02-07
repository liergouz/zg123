
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

// 函数：构造处理
void create()
{
        set_name( "紫参丹" );
        set_picid_1(9167);
        set_picid_2(9167);
        set_unit( "粒" );
        set_value(50);
}

// 函数：获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc() 
{ 
        return "加 20000 点潜能，使用时间间隔：1 秒";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me )
{
	if (me->get_potential()+20000>me->get_max_potential())
	{
		
                send_user( me, "%c%s", '!', "你的潜能已经接近上限，暂时不能使用紫参丹。" );
                return 0;		
	}	
      	if( gone_time( me->get_time("eat_zs") ) < 1 )
        {
                send_user( me, "%c%s", '!', sprintf("服用紫参丹还需等候%d秒", 30 - gone_time( me->get_time("eat_zs") ) ) );
                return 0;
        }        
	me->set_time( "eat_zs", time() );  
        me->add_potential(20000);
        return 1;
}
