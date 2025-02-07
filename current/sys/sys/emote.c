
#include <ansi.h>

#define EMOTE           INI_DIR "emote.ini"

private mapping Emote = ([ ]);

private void load_emote();

// 函数：生成二进制码
void SAVE_BINARY() { }

// 函数：构造处理
private void create() { load_emote(); }

// 函数：读取动作资料
private void load_emote()
{
        string *line, lemma, content, verb;
        int i, size;

        // 读出动作资料
        line = explode( read_file( EMOTE ), "\n" );

        // 历遍动作资料
        size = sizeof(line);
        for( i = 0, verb = ""; i < size; i ++ ) 
        {
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( line[i][<1] <= ' ' ) line[i] = line[i][0..<2];    // UNIX 格式
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( !sscanf( line[i], "%s : %s", lemma, content ) ) 
                {
                        log_file( ERROR, sprintf( "错误: " EMOTE " 第 %d 行动作定义错。\n", i + 1 ) );
                        continue;
                }
                if( lemma == "ACT" ) 
                {
                        verb = content;
                        Emote[verb] = ([ ]);
                        Emote[verb]["none"] = "";
                        Emote[verb]["who"] = "";
                        Emote[verb]["self"] = "";
                        Emote[verb]["note"] = "";
                }
                else if( verb != "" ) switch( lemma ) 
                {
           case "ALL" : Emote[verb]["none"] = content;  break;
           case "WHO" : Emote[verb]["who"] = content;  break;
           case ">ME" : Emote[verb]["self"] = content;  break;
          case "NOTE" : Emote[verb]["note"] = content;  break;
                }
        }
}

// 函数：查询所有动作
string *get_all_emote() { return sort_array( keys(Emote), 1 ); }

// 函数：查询单个动作
mapping get_emote( string verb ) { return undefinedp( Emote[verb] ) ? ([ ]) : Emote[verb]; }

// 函数：查询动作说明
string get_emote_note( string verb ) { return undefinedp( Emote[verb] ) ? "" : Emote[verb]["note"]; }

// -------------------------------------------------------------

// 函数：返回自己尊称
string get_self_respect( object me )    // (爷), 
{
        switch( me->get_gender() )
        {
      default : return "本公公";
       case 1 : switch( me->get_fam_name() )
                {
              default : return "本大爷";
        case "桃花源" : return "本前辈";
          case "蜀山" : return "本大侠";
        case "禁卫军" : return "本将军";
          case "唐门" : return "本大侠";
          case "茅山" : return "本道长";    // 本道
        case "昆仑山" : return "本仙长";    // 本仙
        case "云梦泽" : return "本大师";
                }
       case 2 : switch( me->get_fam_name() )
                {
              default : return "本姑娘";
        case "桃花源" : return "本姑娘";
          case "蜀山" : return "本女侠";
        case "禁卫军" : return "女将军我";
          case "唐门" : return "本女侠";
          case "茅山" : return "本道姑";
        case "昆仑山" : return "本仙姑";
        case "云梦泽" : return "女大师我";
                }
        }
}

// 函数：返回对方尊称
string get_respect( object who )    // (您), 这位(您), 
{
        switch( who->get_gender() )
        {
      default : return "公公";
       case 1 : switch( who->get_fam_name() )
                {
              default : return "大爷";
        case "桃花源" : return "壮士";
          case "蜀山" : return "大侠";
        case "禁卫军" : return "将军";
          case "唐门" : return "大侠";
          case "茅山" : return "道长";    // 道兄
        case "昆仑山" : return "仙长";    // 仙兄
        case "云梦泽" : return "大师";
                }
       case 2 : switch( who->get_fam_name() )
                {
              default : return "姑娘";
        case "桃花源" : return "姑娘";
          case "蜀山" : return "女侠";
        case "禁卫军" : return "女将军";
          case "唐门" : return "女侠";
          case "茅山" : return "道姑";
        case "昆仑山" : return "仙姑";
        case "云梦泽" : return "女大师";
                }
        }
}

// 函数：返回对方贬称
string get_disrespect( object who )    // (小子), 你这(小子), 
{
        switch( who->get_gender() )
        {
      default : return "死太监";
       case 1 : switch( who->get_fam_name() )
                {
              default : return "王八蛋";
        case "桃花源" : return "王八蛋";
          case "蜀山" : return "死臭贼";
        case "禁卫军" : return "死臭贼";
          case "唐门" : return "死臭贼";
          case "茅山" : return "死妖道";    // 死牛鼻子, 死贼道
        case "昆仑山" : return "死妖怪";
        case "云梦泽" : return "老匹夫";
                }
       case 2 : switch( who->get_fam_name() )
                {
              default : return "死贱人";
        case "桃花源" : return "死贱人";
          case "蜀山" : return "贼婆娘";
        case "禁卫军" : return "贼婆娘";
          case "唐门" : return "贼婆娘";
          case "茅山" : return "臭妖女";
        case "昆仑山" : return "臭妖怪";
        case "云梦泽" : return "臭婆娘";
                }
        }
}

// 函数：处理表情动作
string do_emote( object me, string name, string verb, object who )
{
        string result;

        // 禁止非法动作
        if( !verb || !mapp(Emote) || undefinedp( Emote[verb] ) ) return 0;

        // 判断动作对象
        if( !objectp(who) )
        {
                if( !stringp( result = Emote[verb]["none"] ) ) return 0;
                result = replace_string(result, "(我)", HIC+name+NOR );
                result = replace_string(result, "(爷)", get_self_respect(me) );
        }
        else 
        {
                if( me == who )
                {
                        if( !stringp( result = Emote[verb]["self"] ) ) return 0;
                        result = replace_string(result, "(我)", HIC+name+NOR );
                        result = replace_string(result, "(爷)", get_self_respect(me) );
                }
                else
                {
                        if( !stringp( result = Emote[verb]["who"] ) ) return 0;
                        result = replace_string(result, "(我)", HIC+name+NOR );
                        result = replace_string(result, "(爷)", get_self_respect(me) );
                        result = replace_string(result, "(你)", HIC+ who->get_name() + NOR );
                        result = replace_string(result, "(您)", get_respect(who) );
                        result = replace_string(result, "(小子)", get_disrespect(who) );
                }
        }

        return result;
}
