
#include <effect.h>

// 函数：获取描述(持续)
string get_loop_faint_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_FAINT) )
                return sprintf( "眩晕：\n　　陷入眩晕状态后无法进行任何动作。\n" );
        else if( get_effect(me, EFFECT_CHAR_FAINT_2) )
                return sprintf( "眩晕：\n　　陷入眩晕状态后无法进行任何动作。\n" );
        else if( get_effect(me, EFFECT_SLEEP) )   
        	return sprintf( "昏迷：\n　　陷入昏迷状态后无法进行任何动作，\n受伤害后恢复行动。\n" );
        else if( get_effect(me, EFFECT_CHAR_NO_MOVE) )   
        	return sprintf( "不能移动：\n　　陷入这个状态后无法移动。\n可以使用道具法术。\n" );        	
        else
        return sprintf( "眩晕\n" );
}

// 函数：获取描述(持续)
string get_loop_no_pf_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_NO_PF) )
                return sprintf( "封魔：\n　　无法使用任何出招或者法术。\n" );
        else    return sprintf( "封魔\n" );
}

// 函数：获取描述(持续)
string get_loop_slow_desc( object me )
{
	if( get_effect(me, EFFECT_CHAR_SLOW) )
                return sprintf( "延缓：\n　　移动速度变慢 50％。\n" );
        else    return sprintf( "延缓\n" );
}

// 函数：获取描述(持续)
string get_loop_lazy_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_LAZY) )
                return sprintf( "冰冻：\n　　攻击与移动速度均变慢 50％。\n" );
        else    return sprintf( "冰冻\n" );
}

// 函数：获取描述(持续)
string get_loop_dream_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_DREAM_1) )
                return sprintf( "梦游：\n　　无法控制自身，不能攻击、不能使用任何技能、不能使用道具。如果受到攻击便马上恢复正常状态。\n" );
        else    return sprintf( "梦游\n" );
}

// 函数：获取描述(持续)
string get_loop_chaos_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_CHAOS) )
                return sprintf( "混乱：\n　　鼠标操作暂时失控。\n" );
        else    return sprintf( "混乱\n" );
}

// 函数：获取描述(持续)
string get_loop_wound_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_WOUND) )
                return sprintf( "负伤：\n　　物理攻击力与物理防御力下降 30％。\n" );
        else    return sprintf( "负伤\n" );
}

// 函数：获取描述(持续)
string get_loop_blood_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_BLOOD) )
                return sprintf( "流血：\n　　每 2 秒下降气血。\n" );
        else    return sprintf( "流血\n" );
}

// 函数：获取描述(持续)
string get_loop_blind_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_BLIND) )
                return sprintf( "失明：\n　　视线范围缩小为身边八格范围，且命中力下降 50％。\n" );
        else    return sprintf( "失明\n" );
}

// 函数：获取描述(持续)
string get_loop_burn_desc( object me )
{
        if( get_effect(me, EFFECT_USER_BURN) )
                return sprintf( "焚烧：\n　　12秒内无法使用法术恢复气血。" );
        else    return sprintf( "焚烧\n" );
}

// 函数：获取描述(持续)
string get_loop_king_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_KING) )
                return sprintf( "天王散增强：\n　　所有的能力均提升 45％。\n" );
        else    return sprintf( "天王散增强\n" );
}

// 函数：获取描述(持续)
string get_loop_king_2_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_KING_2) )
                return sprintf( "天王散副作用：\n　　气血及法术力均为 1。\n" );
        else    return sprintf( "天王散副作用\n" );
}

// 函数：获取描述(持续)
string get_loop_suppress_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_SUPPRESS) )
                return sprintf( "禁用法宝：\n　　所有带特殊异能的法宝无法使用。\n" );
        else    return sprintf( "禁用法宝\n" );
}
