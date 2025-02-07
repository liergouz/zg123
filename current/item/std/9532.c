
inherit TALISMAN;

// 函数：生效几率
int get_active_rate() { return 75; }

// 函数：法宝识别
int get_talisman_type() { return 4; }

// 函数：构造处理
void create()
{
        set_name( "灵犀环" );
        set_picid_1(9531);
        set_picid_2(9531);
        set_unit( "个" );

        set_level(2);
        set_value(10000);
        set_max_lasting(10099);

        setup();
}

// 函数：获取描述
string get_desc() 
{ 
        return "传送队伍中队友、同帮派的成员、伴侣来自己身边";
}

// 函数：可使用法宝
int is_usable_2() { return 1; }

// 函数：使用法宝效果
int get_use_effect_2( object me, object who, string arg ) { return __DIR__ "9531" ->get_use_effect_2_callout( me, who, this_object(), arg ); }

// 函数：接收法宝效果
int accept_use_effect_2( object me, object who ) { return __DIR__ "9531" ->accept_use_effect_2_callout(me, who); }
