
#include <ansi.h>
#include <skill.h>
#include <item.h>

#define MAX_HERB        40              // 药类总数

// 函数：生成二进制码
void SAVE_BINARY() { }

// 函数：毒药合成
void make_poison( object me, object item1, int amount1, object item2, int amount2, object item3, int amount3, object item4, int amount4 )
{
        object *item, item5;
        string name, result;
        int *amount, p1, p2, flag, flag2, poison, poison2;
        int level, level2, mp, z, p, i, j, size;

        item = ({ item1, item2, item3, item4 });
        amount = ({ amount1, amount2, amount3, amount4 });
        flag = 0;  flag2 = 0;

        for( i = 0; i < 4; i ++ ) if( objectp( item[i] ) )
        {
                if( !item[i]->is_poison() )    // 必须得是毒药
                {
                        item[i] = 0;  amount[i] = 0;
                        continue;
                }
                for( j = 0; j < i - 1; j ++ ) if( item[i] == item[j] )    // 是否重复放置？
                {
                        send_user( me, "%c%s", '!', sprintf( "第 %d 样原料%s已经有了。", i + 1, item[i]->get_name() ) );
                        return;
                }
                if( amount[i] < 1 || amount[i] > item[i]->get_amount() )    // 数量是否正确？
                {
                        send_user( me, "%c%s", '!', sprintf( "第 %d 样原料%s数量不对。", i + 1, item[i]->get_name() ) );
                        return;
                }
                switch( item[i]->get_name() )    // 累加同类数量
                {
                  case "砒霜" : flag += amount[i];  break;
                case "鹤顶红" : flag2 += amount[i];  break;
                }
        }
        else
        {
                item[i] = 0;  amount[i] = 0;
        }

        level2 = PF_FILE_05212->get_skill_level();

        if( !me->get_skill(SKILL_0501) )    // 中医药理
        {
                write_user( me, ECHO "使用“炼毒”得先学会中医药理。" );
                return;
        }
        if( ( level = me->get_skill(SKILL_0521) ) < level2 )    // 毒经
        {
                write_user( me, ECHO "使用“炼毒”得先学会 %d 级毒经。", level2 );
                return;
        }

        mp = PF_FILE_05212->get_sub_mp(me);

        if( me->get_mp() < mp )
        {
                write_user( me, ECHO "使用“炼毒”需要 %d 点法力。", mp );
                return;
        }

        if( flag < 30 && flag2 < 30 )
        {
                send_user( me, "%c%s", '!', "炼毒原料数量不够。" );
                return;
        }

        flag /= 30;  p1 = flag * 30;
        flag2 /= 30;  p2 = flag2 * 30;

        result = "";

        for( i = 0; i < 4; i ++ ) if( amount[i] > 0 && item[i] )    // 确认原料需求
        {
                p = 0;

                if( p1 && item[i]->get_name() == "砒霜" ) 
                {
                        if( p1 > amount[i] ) p1 -= amount[i];
                        else { amount[i] = p1;  p1 = 0; }
                        p = 1;
                }
                else if( p2 && item[i]->get_name() == "鹤顶红" ) 
                {
                        if( p2 > amount[i] ) p2 -= amount[i];
                        else { amount[i] = p2;  p2 = 0; }
                        p = 1;
                }

                if( !p ) continue;    // 不需要此原料

                name = sprintf( " %s", item[i]->get_name() );

                if( result == "" ) result = name;
                else result = sprintf( "%s、%s", result, name );

                if( amount[i] < item[i]->get_amount() )
                        item[i]->add_amount( -amount[i] );
                else
                {
                        item[i]->remove_from_user();
                        destruct( item[i] );
                }
        }

        result += "炼制成";

        poison = ITEM_5210_FILE->get_poison();
        poison2 = ITEM_5211_FILE->get_poison();

        z = get_z(me);

        for( i = 0; i < flag; i ++ )
        {
                item5 = new( ITEM_9130_FILE );    // 砒霜粉
                item5->set_poison( PF_FILE_05212->get_add_poison(me, poison) );
                item5->set_amount(flag);
                if( i == 0 ) result = sprintf( "%s %s", result, item5->get_name() );
                if( p = item5->move(me, -1) ) 
                        item5->add_to_user(p);
                else if( p = get_valid_xy(z, get_x(me), get_y(me), IS_ITEM_BLOCK) )
                        item5->add_to_scene(z, p / 1000, p % 1000);
                else    destruct(item5);
        }
        for( i = 0; i < flag2; i ++ )
        {
                item5 = new( ITEM_9131_FILE );    // 鹤顶红粉
                item5->set_poison( PF_FILE_05212->get_add_poison(me, poison2) );
                item5->set_amount(flag2);
                if( i == 0 ) result = sprintf( "%s %s", result, item5->get_name() );
                if( p = item5->move(me, -1) ) 
                        item5->add_to_user(p);
                else if( p = get_valid_xy(z, get_x(me), get_y(me), IS_ITEM_BLOCK) )
                        item5->add_to_scene(z, p / 1000, p % 1000);
                else    destruct(item5);
        }

        me->add_mp(-mp);

        write_user( me, ECHO "您将%s。", result );
}

// 函数：毒药合成(％)
void make_poison_check( object me, object item1, int amount1, object item2, int amount2, object item3, int amount3, object item4, int amount4 )
{
        object *item, item5;
        string name, result;
        int *amount, p1, p2, flag, flag2;
        int level, level2, mp, p, i, j, size;

        item = ({ item1, item2, item3, item4 });
        amount = ({ amount1, amount2, amount3, amount4 });
        flag = 0;  flag2 = 0;

        for( i = 0; i < 4; i ++ ) if( objectp( item[i] ) )
        {
                if( !item[i]->is_poison() )    // 必须得是毒药
                {
                        item[i] = 0;  amount[i] = 0;
                        continue;
                }
                for( j = 0; j < i - 1; j ++ ) if( item[i] == item[j] )    // 是否重复放置？
                {
                        send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
                        return;
                }
                if( amount[i] < 1 || amount[i] > item[i]->get_amount() )    // 数量是否正确？
                {
                        send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
                        return;
                }
                switch( item[i]->get_name() )    // 累加同类数量
                {
                  case "砒霜" : flag += amount[i];  break;
                case "鹤顶红" : flag2 += amount[i];  break;
                }
        }
        else
        {
                item[i] = 0;  amount[i] = 0;
        }

        level2 = PF_FILE_05212->get_skill_level();

        if( !me->get_skill(SKILL_0501) )    // 中医药理
        {
                send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
                return;
        }
        if( ( level = me->get_skill(SKILL_0521) ) < level2 )    // 毒经
        {
                send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
                return;
        }

        mp = PF_FILE_05212->get_sub_mp(me);

        if( me->get_mp() < mp )
        {
                send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
                return;
        }

/*      if( flag < 30 && flag2 < 30 )
        {
                send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
                return;
        }       */

        send_user( me, "%c%c%c%d", 0x25, 0, 100, 0 );
}

// 函数：获取最小数目
varargs int min_number( int n1, int n2, int n3, int n4 )
{
        int min = 1000;
        if( n1 && n1 < min ) min = n1;
        if( n2 && n2 < min ) min = n2;
        if( n3 && n3 < min ) min = n3;
        if( n4 && n4 < min ) min = n4;
        return min;
}

// 函数：草药合成
void make_herb( object me, object item1, int amount1, object item2, int amount2, object item3, int amount3, object item4, int amount4 )
{
        object *item, item5;
        string file, name, result;
        int *amount, *herb, level, level2, level3, rate, rate2;
        int z, p, p1, i, j, size;

        item = ({ item1, item2, item3, item4 });
        amount = ({ amount1, amount2, amount3, amount4 });

        herb = ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,       // 板蓝根 金银花 田七 罂粟果 野菊 黄芪 何首乌 罗汉果 穿心莲 黄连
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,       // 洋金花 陈皮 红枣 灵芝草 生地 桔梗 山参 甘草 白芪 当归
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,       // 川贝 冬虫草 番红花 龙骨 牛黄 鹿茸 麝香 蟾酥 古石灰 雄黄
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });    // 吡石 砂汞 硫磺 慈石 绿矾

        for( i = 0; i < 4; i ++ ) if( objectp( item[i] ) )
        {
                if( !item[i]->is_herb() )    // 必须得是草药
                {
                        item[i] = 0;  amount[i] = 0;
                        continue;
                }
                for( j = 0; j < i - 1; j ++ ) if( item[i] == item[j] )    // 是否重复放置？
                {
                        send_user( me, "%c%s", '!', sprintf( "第 %d 样原料%s已经有了。", i + 1, item[i]->get_name() ) );
                        return;
                }
                if( amount[i] < 1 || amount[i] > item[i]->get_amount() )    // 数量是否正确？
                {
                        send_user( me, "%c%s", '!', sprintf( "第 %d 样原料%s数量不对。", i + 1, item[i]->get_name() ) );
                        return;
                }
                switch( item[i]->get_name() )    // 累加同类数量
                {
                case "板蓝根" : herb[0] += amount[i];  break;
                case "金银花" : herb[1] += amount[i];  break;
                  case "田七" : herb[2] += amount[i];  break;
                case "罂粟果" : herb[3] += amount[i];  break;
                  case "野菊" : herb[4] += amount[i];  break;
                  case "黄芪" : herb[5] += amount[i];  break;
                case "何首乌" : herb[6] += amount[i];  break;
                case "罗汉果" : herb[7] += amount[i];  break;
                case "穿心莲" : herb[8] += amount[i];  break;
                  case "黄连" : herb[9] += amount[i];  break;

                case "洋金花" : herb[10] += amount[i];  break;
                  case "陈皮" : herb[11] += amount[i];  break;
                  case "红枣" : herb[12] += amount[i];  break;
                case "灵芝草" : herb[13] += amount[i];  break;
                  case "生地" : herb[14] += amount[i];  break;
                  case "桔梗" : herb[15] += amount[i];  break;
                  case "山参" : herb[16] += amount[i];  break;
                  case "甘草" : herb[17] += amount[i];  break;
                  case "白芪" : herb[18] += amount[i];  break;
                  case "当归" : herb[19] += amount[i];  break;

                  case "川贝" : herb[20] += amount[i];  break;
                case "冬虫草" : herb[21] += amount[i];  break;
                case "番红花" : herb[22] += amount[i];  break;
                  case "龙骨" : herb[23] += amount[i];  break;
                  case "牛黄" : herb[24] += amount[i];  break;
                  case "鹿茸" : herb[25] += amount[i];  break;
                  case "麝香" : herb[26] += amount[i];  break;
                  case "蟾酥" : herb[27] += amount[i];  break;
                case "古石灰" : herb[28] += amount[i];  break;
                  case "雄黄" : herb[29] += amount[i];  break;

                  case "吡石" : herb[30] += amount[i];  break;
                  case "砂汞" : herb[31] += amount[i];  break;
                  case "硫磺" : herb[32] += amount[i];  break;
                  case "慈石" : herb[33] += amount[i];  break;
                  case "绿矾" : herb[34] += amount[i];  break;
                }
        }
        else
        {
                item[i] = 0;  amount[i] = 0;
        }

        if( !( level = me->get_skill(SKILL_0503) ) )    // 炼丹术  // 这里如果有基本技能时，就不管高级技能，太过份了。
        {
                level = me->get_skill(SKILL_0513);    // 金丹法门
                level3 = level;
        }
        else    level2 = level;

        p = 0;

        // 还缺：9100 行军散 9110 正气散

        if( !p && level >= 13 )
        {
                if( !p && herb[7] && herb[12] && herb[28] )    // 活络丸：罗汉果＋红枣＋古石灰
                {
                        file = "/item/91/9101";
                        size = min_number(herb[7], herb[12], herb[28]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[7] = size;  herb[12] = size;  herb[28] = size;
                        rate = 18;  rate2 = 35;
                        p = 1;
                }

        if( !p && level >= 14 )
        {
                if( !p && herb[5] && herb[20] && herb[24] )    // 安神丸：黄芪＋川贝＋牛黄
                {
                        file = "/item/91/9111";
                        size = min_number(herb[5], herb[20], herb[24]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[5] = size;  herb[20] = size;  herb[24] = size;
                        rate = 18;  rate2 = 35;
                        p = 1;
                }

        if( !p && level >= 19 )
        {
                if( !p && herb[12] && herb[19] && herb[28] )    // 造化丹：红枣＋当归＋古石灰
                {
                        file = "/item/91/9102";
                        size = min_number(herb[12], herb[19], herb[28]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[12] = size;  herb[19] = size;  herb[28] = size;
                        rate = 14;  rate2 = 30;
                        p = 1;
                }

        if( !p && level >= 20 )
        {
                if( !p && herb[4] && herb[21] && herb[26] )    // 补心丹：野菊＋冬虫草＋麝香
                {
                        file = "/item/91/9112";
                        size = min_number(herb[4], herb[21], herb[26]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[4] = size;  herb[21] = size;  herb[26] = size;
                        rate = 14;  rate2 = 29;
                        p = 1;
                }

        if( !p && level >= 24 )
        {
                if( !p && herb[3] && herb[10] && herb[23] && herb[31] )    // 迷神散：罂粟果＋洋金花＋龙骨＋砂汞
                {
                        file = "/item/std/5216";
                        size = min_number(herb[3], herb[10], herb[23], herb[31]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[3] = size;  herb[10] = size;  herb[23] = size;  herb[31] = size;
                        rate = 0;  rate2 = 25;
                        p = 1;
                }

        if( !p && level >= 25 )
        {
                if( !p && herb[9] && herb[30] && herb[31] && herb[32] )    // 毒药：黄连＋吡石＋砂汞＋硫磺
                {
                        file = "/item/std/5210";
                        size = min_number(herb[9], herb[30], herb[31], herb[32]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[9] = size;  herb[30] = size;  herb[31] = size;  herb[32] = size;
                        rate = 0;  rate2 = 33;
                        p = 1;
                }

        if( !p && level >= 26 )
        {
                if( !p && herb[17] && herb[24] && herb[26] && herb[34] )    // 辟毒散：甘草＋牛黄＋麝香＋绿矾
                {
                        file = "/item/91/9140";
                        size = min_number(herb[17], herb[24], herb[26], herb[34]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[17] = size;  herb[24] = size;  herb[26] = size;  herb[34] = size;
                        rate = 20;  rate2 = 40;
                        p = 1;
                }

        if( !p && level >= 28 )
        {
                if( !p && herb[6] && herb[14] && herb[18] && herb[19] )    // 救急丹：何首乌＋生地＋白芪＋当归
                {
                        file = "/item/91/9120";
                        size = min_number(herb[6], herb[14], herb[18], herb[19]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[6] = size;  herb[14] = size;  herb[18] = size;  herb[19] = size;
                        rate = 10;  rate2 = 25;
                        p = 1;
                }

        if( !p && level >= 29 )
        {
                if( !p && herb[0] && herb[2] && herb[15] && herb[26] )    // 活心丹：板蓝根＋田七＋桔梗＋麝香
                {
                        file = "/item/91/9121";
                        size = min_number(herb[0], herb[2], herb[15], herb[26]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[0] = size;  herb[2] = size;  herb[15] = size;  herb[26] = size;
                        rate = 10;  rate2 = 25;
                        p = 1;
                }

        if( !p && level >= 32 )
        {
                if( !p && herb[1] && herb[8] && herb[27] && herb[33] )    // 清心丹：金银花＋穿心莲＋蟾酥＋慈石
                {
                        file = "/item/91/9145";
                        size = min_number(herb[1], herb[8], herb[27], herb[33]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[1] = size;  herb[8] = size;  herb[27] = size;  herb[33] = size;
                        rate = 14;  rate2 = 28;
                        p = 1;
                }

        if( !p && level >= 33 )
        {
                if( !p && herb[13] && herb[16] && herb[22] && herb[25] )    // 再造丸：灵芝草＋山参＋番红花＋鹿茸
                {
                        file = "/item/91/9125";
                        size = min_number(herb[13], herb[16], herb[22], herb[25]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[13] = size;  herb[16] = size;  herb[22] = size;  herb[25] = size;
                        rate = 0;  rate2 = 15;
                        p = 1;
                }

        if( !p && level >= 35 )
        {
                if( !p && herb[3] && herb[27] && herb[30] && herb[31] )    // 剧毒：罂粟果＋蟾酥＋吡石＋砂汞
                {
                        file = "/item/std/5211";
                        size = min_number(herb[3], herb[27], herb[30], herb[31]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[3] = size;  herb[27] = size;  herb[30] = size;  herb[31] = size;
                        rate = 0;  rate2 = 20;
                        p = 1;
                }

        if( !p && level >= 46 )
        {
                if( !p && herb[3] && herb[10] && herb[27] && herb[31] )    // 软筋散：罂粟果＋洋金花＋蟾酥＋砂汞
                {
                        file = "/item/std/5215";
                        size = min_number(herb[3], herb[10], herb[27], herb[31]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[3] = size;  herb[10] = size;  herb[27] = size;  herb[31] = size;
                        rate = 0;  rate2 = 25;
                        p = 1;
                }
                if( !p && level3 >= 46 && herb[6] && herb[13] && herb[16] && herb[25] ) // 九转混天丹：何首乌＋灵芝草＋山参＋鹿茸
                {
                        file = "/item/std/0088";
                        size = min_number(herb[6], herb[13], herb[16], herb[25]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[6] = size;  herb[13] = size;  herb[16] = size;  herb[25] = size;
                        rate = 0;  rate2 = 40;
                        p = 1;
                }

        if( !p && level >= 48 )
        {
                if( !p && herb[3] && herb[10] && herb[16] && herb[27] )    // 麻沸散：罂粟果＋洋金花＋山参＋蟾酥
                {
                        file = "/item/std/5219";
                        size = min_number(herb[3], herb[10], herb[16], herb[27]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[3] = size;  herb[10] = size;  herb[16] = size;  herb[27] = size;
                        rate = 0;  rate2 = 18;
                        p = 1;
                }

        if( !p && level >= 70 )
        {
                if( !p && herb[3] && herb[10] && herb[22] && herb[25] )    // 天王散：罂粟果＋洋金花＋番红花＋鹿茸
                {
                        file = "/item/91/9150";
                        size = min_number(herb[3], herb[10], herb[22], herb[25]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[3] = size;  herb[10] = size;  herb[22] = size;  herb[25] = size;
                        rate = 0;  rate2 = 10;
                        p = 1;
                }
        }

        if( !p && level >= 73 )
        {
                if( !p && level2 >= 73 && herb[6] && herb[13] && herb[16] && herb[25] ) // 九转混天丹：何首乌＋灵芝草＋山参＋鹿茸
                {
                        file = "/item/std/0088";
                        size = min_number(herb[6], herb[13], herb[16], herb[25]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[6] = size;  herb[13] = size;  herb[16] = size;  herb[25] = size;
                        rate = 10;  rate2 = 0;
                        p = 1;
                }
        }

        }

        }

        }

        }

        }

        }

        }

        }

        }

        }

        }

        }

        }

        }

        if( !p )
        {
                write_user( me, ECHO "您炼制的配方不对！" );
                return;
        }

        if( me->get_skill(SKILL_0503) )    // 炼丹术
        {
                if( !rate )
                {
                        write_user( me, ECHO "您炼制的配方不对！" );
                        return;
                }
                rate = rate + level / 20 + me->get_lucky();
        }
        else 
        {
                if( !rate2 )
                {
                        write_user( me, ECHO "您炼制的配方不对！" );
                        return;
                }
                rate = rate2 + level / 5 + me->get_lucky();
        }

        result = "";

        for( i = 0; i < 4; i ++ ) if( amount[i] > 0 && item[i] )    // 确认原料需求
        {
                p = 0;

                switch( item[i]->get_name() )
                {
                case "板蓝根" : if( p1 = herb[0] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "金银花" : if( p1 = herb[1] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "田七" : if( p1 = herb[2] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "罂粟果" : if( p1 = herb[3] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "野菊" : if( p1 = herb[4] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "黄芪" : if( p1 = herb[5] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "何首乌" : if( p1 = herb[6] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "罗汉果" : if( p1 = herb[7] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "穿心莲" : if( p1 = herb[8] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "黄连" : if( p1 = herb[9] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;

                case "洋金花" : if( p1 = herb[10] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "陈皮" : if( p1 = herb[11] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "红枣" : if( p1 = herb[12] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "灵芝草" : if( p1 = herb[13] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "生地" : if( p1 = herb[14] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "桔梗" : if( p1 = herb[15] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "山参" : if( p1 = herb[16] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "甘草" : if( p1 = herb[17] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "白芪" : if( p1 = herb[18] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "当归" : if( p1 = herb[19] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                   case "川贝" : if( p1 = herb[20] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "冬虫草" : if( p1 = herb[21] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "番红花" : if( p1 = herb[22] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "龙骨" : if( p1 = herb[23] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "牛黄" : if( p1 = herb[24] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "鹿茸" : if( p1 = herb[25] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "麝香" : if( p1 = herb[26] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "蟾酥" : if( p1 = herb[27] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "古石灰" : if( p1 = herb[28] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "雄黄" : if( p1 = herb[29] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;

                  case "吡石" : if( p1 = herb[30] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "砂汞" : if( p1 = herb[31] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "硫磺" : if( p1 = herb[32] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "慈石" : if( p1 = herb[33] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "绿矾" : if( p1 = herb[34] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                }

                if( !p ) continue;    // 不需要此原料

                name = sprintf( " %s", item[i]->get_name() );

                if( result == "" ) result = name;
                else result = sprintf( "%s、%s", result, name );

                if( amount[i] < item[i]->get_amount() )
                        item[i]->add_amount( -amount[i] );
                else
                {
                        item[i]->remove_from_user();
                        destruct( item[i] );
                }
        }

        for( i = 0, p = 0; i < size; i ++ ) if( random(100) < rate ) p ++;

        if( p && load_object(file) )
        {
                write_user( me, ECHO "您将%s炼制成 %s。(%d 次炼制失败)", result, file->get_name(), size - p );

                z = get_z(me);

                if( file->is_combined() )
                {
                        item5 = new(file);
                        item5->set_amount(p);
                        if( p = item5->move(me, -1) ) 
                                item5->add_to_user(p);
                        else if( p = get_valid_xy(z, get_x(me), get_y(me), IS_ITEM_BLOCK) )
                                item5->add_to_scene(z, p / 1000, p % 1000);
                        else    destruct(item5);
                }
                else for( i = 0, size = p; i < size; i ++ )
                {
                        item5 = new(file);
                        if( p = item5->move(me, -1) ) 
                                item5->add_to_user(p);
                        else if( p = get_valid_xy(z, get_x(me), get_y(me), IS_ITEM_BLOCK) )
                                item5->add_to_scene(z, p / 1000, p % 1000);
                        else    destruct(item5);
                }
        }
        else    write_user( me, ECHO "您将%s进行炼制，全部失败！", result );
}

// 函数：草药合成(％)
void make_herb_check( object me, object item1, int amount1, object item2, int amount2, object item3, int amount3, object item4, int amount4 )
{
        object *item, item5;
        string file, name, result;
        int *amount, *herb, level, level2, level3, rate, rate2;
        int p, p1, i, j, size;

        item = ({ item1, item2, item3, item4 });
        amount = ({ amount1, amount2, amount3, amount4 });

        herb = ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,       // 板蓝根 金银花 田七 罂粟果 野菊 黄芪 何首乌 罗汉果 穿心莲 黄连
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,       // 洋金花 陈皮 红枣 灵芝草 生地 桔梗 山参 甘草 白芪 当归
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,       // 川贝 冬虫草 番红花 龙骨 牛黄 鹿茸 麝香 蟾酥 古石灰 雄黄
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });    // 吡石 砂汞 硫磺 慈石 绿矾

        for( i = 0; i < 4; i ++ ) if( objectp( item[i] ) )
        {
                if( !item[i]->is_herb() )    // 必须得是草药
                {
                        item[i] = 0;  amount[i] = 0;
                        continue;
                }
                for( j = 0; j < i - 1; j ++ ) if( item[i] == item[j] )    // 是否重复放置？
                {
                        send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
                        return;
                }
                if( amount[i] < 1 || amount[i] > item[i]->get_amount() )    // 数量是否正确？
                {
                        send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
                        return;
                }
                switch( item[i]->get_name() )    // 累加同类数量
                {
                case "板蓝根" : herb[0] += amount[i];  break;
                case "金银花" : herb[1] += amount[i];  break;
                  case "田七" : herb[2] += amount[i];  break;
                case "罂粟果" : herb[3] += amount[i];  break;
                  case "野菊" : herb[4] += amount[i];  break;
                  case "黄芪" : herb[5] += amount[i];  break;
                case "何首乌" : herb[6] += amount[i];  break;
                case "罗汉果" : herb[7] += amount[i];  break;
                case "穿心莲" : herb[8] += amount[i];  break;
                  case "黄连" : herb[9] += amount[i];  break;

                case "洋金花" : herb[10] += amount[i];  break;
                  case "陈皮" : herb[11] += amount[i];  break;
                  case "红枣" : herb[12] += amount[i];  break;
                case "灵芝草" : herb[13] += amount[i];  break;
                  case "生地" : herb[14] += amount[i];  break;
                  case "桔梗" : herb[15] += amount[i];  break;
                  case "山参" : herb[16] += amount[i];  break;
                  case "甘草" : herb[17] += amount[i];  break;
                  case "白芪" : herb[18] += amount[i];  break;
                  case "当归" : herb[19] += amount[i];  break;

                  case "川贝" : herb[20] += amount[i];  break;
                case "冬虫草" : herb[21] += amount[i];  break;
                case "番红花" : herb[22] += amount[i];  break;
                  case "龙骨" : herb[23] += amount[i];  break;
                  case "牛黄" : herb[24] += amount[i];  break;
                  case "鹿茸" : herb[25] += amount[i];  break;
                  case "麝香" : herb[26] += amount[i];  break;
                  case "蟾酥" : herb[27] += amount[i];  break;
                case "古石灰" : herb[28] += amount[i];  break;
                  case "雄黄" : herb[29] += amount[i];  break;

                  case "吡石" : herb[30] += amount[i];  break;
                  case "砂汞" : herb[31] += amount[i];  break;
                  case "硫磺" : herb[32] += amount[i];  break;
                  case "慈石" : herb[33] += amount[i];  break;
                  case "绿矾" : herb[34] += amount[i];  break;
                }
        }
        else
        {
                item[i] = 0;  amount[i] = 0;
        }

        if( !( level = me->get_skill(SKILL_0503) ) )    // 炼丹术
        {
                level = me->get_skill(SKILL_0513);    // 金丹法门
                level3 = level;
        }
        else    level2 = level;

        p = 0;

        // 还缺：9100 行军散 9110 正气散

        if( !p && level >= 13 )
        {
                if( !p && herb[7] && herb[12] && herb[28] )    // 活络丸：罗汉果＋红枣＋古石灰
                {
                        file = "/item/91/9101";
                        size = min_number(herb[7], herb[12], herb[28]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[7] = size;  herb[12] = size;  herb[28] = size;
                        rate = 18;  rate2 = 35;
                        p = 1;
                }

        if( !p && level >= 14 )
        {
                if( !p && herb[5] && herb[20] && herb[24] )    // 安神丸：黄芪＋川贝＋牛黄
                {
                        file = "/item/91/9111";
                        size = min_number(herb[5], herb[20], herb[24]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[5] = size;  herb[20] = size;  herb[24] = size;
                        rate = 18;  rate2 = 35;
                        p = 1;
                }

        if( !p && level >= 19 )
        {
                if( !p && herb[12] && herb[19] && herb[28] )    // 造化丹：红枣＋当归＋古石灰
                {
                        file = "/item/91/9102";
                        size = min_number(herb[12], herb[19], herb[28]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[12] = size;  herb[19] = size;  herb[28] = size;
                        rate = 14;  rate2 = 30;
                        p = 1;
                }

        if( !p && level >= 20 )
        {
                if( !p && herb[4] && herb[21] && herb[26] )    // 补心丹：野菊＋冬虫草＋麝香
                {
                        file = "/item/91/9112";
                        size = min_number(herb[4], herb[21], herb[26]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[4] = size;  herb[21] = size;  herb[26] = size;
                        rate = 14;  rate2 = 29;
                        p = 1;
                }

        if( !p && level >= 24 )
        {
                if( !p && herb[3] && herb[10] && herb[23] && herb[31] )    // 迷神散：罂粟果＋洋金花＋龙骨＋砂汞
                {
                        file = "/item/std/5216";
                        size = min_number(herb[3], herb[10], herb[23], herb[31]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[3] = size;  herb[10] = size;  herb[23] = size;  herb[31] = size;
                        rate = 0;  rate2 = 25;
                        p = 1;
                }

        if( !p && level >= 25 )
        {
                if( !p && herb[9] && herb[30] && herb[31] && herb[32] )    // 毒药：黄连＋吡石＋砂汞＋硫磺
                {
                        file = "/item/std/5210";
                        size = min_number(herb[9], herb[30], herb[31], herb[32]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[9] = size;  herb[30] = size;  herb[31] = size;  herb[32] = size;
                        rate = 0;  rate2 = 33;
                        p = 1;
                }

        if( !p && level >= 26 )
        {
                if( !p && herb[17] && herb[24] && herb[26] && herb[34] )    // 辟毒散：甘草＋牛黄＋麝香＋绿矾
                {
                        file = "/item/91/9140";
                        size = min_number(herb[17], herb[24], herb[26], herb[34]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[17] = size;  herb[24] = size;  herb[26] = size;  herb[34] = size;
                        rate = 20;  rate2 = 40;
                        p = 1;
                }

        if( !p && level >= 28 )
        {
                if( !p && herb[6] && herb[14] && herb[18] && herb[19] )    // 救急丹：何首乌＋生地＋白芪＋当归
                {
                        file = "/item/91/9120";
                        size = min_number(herb[6], herb[14], herb[18], herb[19]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[6] = size;  herb[14] = size;  herb[18] = size;  herb[19] = size;
                        rate = 10;  rate2 = 25;
                        p = 1;
                }

        if( !p && level >= 29 )
        {
                if( !p && herb[0] && herb[2] && herb[15] && herb[26] )    // 活心丹：板蓝根＋田七＋桔梗＋麝香
                {
                        file = "/item/91/9121";
                        size = min_number(herb[0], herb[2], herb[15], herb[26]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[0] = size;  herb[2] = size;  herb[15] = size;  herb[26] = size;
                        rate = 10;  rate2 = 25;
                        p = 1;
                }

        if( !p && level >= 32 )
        {
                if( !p && herb[1] && herb[8] && herb[27] && herb[33] )    // 清心丹：金银花＋穿心莲＋蟾酥＋慈石
                {
                        file = "/item/91/9145";
                        size = min_number(herb[1], herb[8], herb[27], herb[33]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[1] = size;  herb[8] = size;  herb[27] = size;  herb[33] = size;
                        rate = 14;  rate2 = 28;
                        p = 1;
                }

        if( !p && level >= 33 )
        {
                if( !p && herb[13] && herb[16] && herb[22] && herb[25] )    // 再造丸：灵芝草＋山参＋番红花＋鹿茸
                {
                        file = "/item/91/9125";
                        size = min_number(herb[13], herb[16], herb[22], herb[25]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[13] = size;  herb[16] = size;  herb[22] = size;  herb[25] = size;
                        rate = 0;  rate2 = 15;
                        p = 1;
                }

        if( !p && level >= 35 )
        {
                if( !p && herb[3] && herb[27] && herb[30] && herb[31] )    // 剧毒：罂粟果＋蟾酥＋吡石＋砂汞
                {
                        file = "/item/std/5211";
                        size = min_number(herb[3], herb[27], herb[30], herb[31]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[3] = size;  herb[27] = size;  herb[30] = size;  herb[31] = size;
                        rate = 0;  rate2 = 20;
                        p = 1;
                }

        if( !p && level >= 46 )
        {
                if( !p && herb[3] && herb[10] && herb[27] && herb[31] )    // 软筋散：罂粟果＋洋金花＋蟾酥＋砂汞
                {
                        file = "/item/std/5215";
                        size = min_number(herb[3], herb[10], herb[27], herb[31]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[3] = size;  herb[10] = size;  herb[27] = size;  herb[31] = size;
                        rate = 0;  rate2 = 25;
                        p = 1;
                }
                if( !p && level3 >= 46 && herb[6] && herb[13] && herb[16] && herb[25] ) // 九转混天丹：何首乌＋灵芝草＋山参＋鹿茸
                {
                        file = "/item/std/0088";
                        size = min_number(herb[6], herb[13], herb[16], herb[25]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[6] = size;  herb[13] = size;  herb[16] = size;  herb[25] = size;
                        rate = 0;  rate2 = 40;
                        p = 1;
                }

        if( !p && level >= 48 )
        {
                if( !p && herb[3] && herb[10] && herb[16] && herb[27] )    // 麻沸散：罂粟果＋洋金花＋山参＋蟾酥
                {
                        file = "/item/std/5219";
                        size = min_number(herb[3], herb[10], herb[16], herb[27]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[3] = size;  herb[10] = size;  herb[16] = size;  herb[27] = size;
                        rate = 0;  rate2 = 18;
                        p = 1;
                }

        if( !p && level >= 70 )
        {
                if( !p && herb[3] && herb[10] && herb[22] && herb[25] )    // 天王散：罂粟果＋洋金花＋番红花＋鹿茸
                {
                        file = "/item/91/9150";
                        size = min_number(herb[3], herb[10], herb[22], herb[25]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[3] = size;  herb[10] = size;  herb[22] = size;  herb[25] = size;
                        rate = 0;  rate2 = 10;
                        p = 1;
                }

        if( !p && level >= 73 )
        {
                if( !p && level2 >= 73 && herb[6] && herb[13] && herb[16] && herb[25] ) // 九转混天丹：何首乌＋灵芝草＋山参＋鹿茸
                {
                        file = "/item/std/0088";
                        size = min_number(herb[6], herb[13], herb[16], herb[25]);
                        for( i = 0; i < MAX_HERB; i ++ ) herb[i] = 0;
                        herb[6] = size;  herb[13] = size;  herb[16] = size;  herb[25] = size;
                        rate = 10;  rate2 = 0;
                        p = 1;
                }
        }

        }

        }

        }

        }

        }

        }

        }

        }

        }

        }

        }

        }

        }

        }

        }

        if( !p )
        {
                send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
                return;
        }

        if( me->get_skill(SKILL_0503) )    // 炼丹术
        {
                if( !rate )
                {
                        send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
                        return;
                }
                rate = rate + level / 20 + me->get_lucky();
        }
        else 
        {
                if( !rate2 )
                {
                        send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
                        return;
                }
                rate = rate2 + level / 5 + me->get_lucky();
        }

//      result = "";

        for( i = 0; i < 4; i ++ ) if( amount[i] > 0 && item[i] )    // 确认原料需求
        {
                p = 0;

                switch( item[i]->get_name() )
                {
                case "板蓝根" : if( p1 = herb[0] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "金银花" : if( p1 = herb[1] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "田七" : if( p1 = herb[2] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "罂粟果" : if( p1 = herb[3] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "野菊" : if( p1 = herb[4] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "黄芪" : if( p1 = herb[5] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "何首乌" : if( p1 = herb[6] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "罗汉果" : if( p1 = herb[7] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "穿心莲" : if( p1 = herb[8] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "黄连" : if( p1 = herb[9] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;

                case "洋金花" : if( p1 = herb[10] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "陈皮" : if( p1 = herb[11] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "红枣" : if( p1 = herb[12] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "灵芝草" : if( p1 = herb[13] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "生地" : if( p1 = herb[14] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "桔梗" : if( p1 = herb[15] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "山参" : if( p1 = herb[16] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "甘草" : if( p1 = herb[17] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "白芪" : if( p1 = herb[18] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "当归" : if( p1 = herb[19] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                   case "川贝" : if( p1 = herb[20] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "冬虫草" : if( p1 = herb[21] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "番红花" : if( p1 = herb[22] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "龙骨" : if( p1 = herb[23] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "牛黄" : if( p1 = herb[24] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "鹿茸" : if( p1 = herb[25] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "麝香" : if( p1 = herb[26] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "蟾酥" : if( p1 = herb[27] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                case "古石灰" : if( p1 = herb[28] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "雄黄" : if( p1 = herb[29] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;

                  case "吡石" : if( p1 = herb[30] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "砂汞" : if( p1 = herb[31] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "硫磺" : if( p1 = herb[32] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "慈石" : if( p1 = herb[33] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                  case "绿矾" : if( p1 = herb[34] )
                                {
                                        if( p1 > amount[i] ) p1 -= amount[i];
                                        else { amount[i] = p1;  p1 = 0; }
                                        p = 1;
                                }
                                break;
                }

                if( !p ) continue;    // 不需要此原料

                name = sprintf( " %s", item[i]->get_name() );

//              if( result == "" ) result = name;
//              else result = sprintf( "%s、%s", result, name );

/*              if( amount[i] < item[i]->get_amount() )
                        item[i]->add_amount( -amount[i] );
                else
                {
                        item[i]->remove_from_user();
                        destruct( item[i] );
                }       */
        }

        send_user( me, "%c%c%c%d", 0x25, 0, rate, 0 );
}
