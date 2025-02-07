
#include <ansi.h>

#define TIPS            "/quest/tips.txt"

private string *TipsA = ({ });          // ������ʾ
private string *TipsB = ({ });          // �ͼ���ʾ
private string *TipsC = ({ });          // ������ʾ

private string *Battle = ({ });         // ս����ʾ

private int sizeof_TipsA, sizeof_TipsB, sizeof_TipsC, sizeof_Battle;

private int TipsCount = 0;              // ��ʾ������

private void load_tips();

// ���������ɶ�������
void SAVE_BINARY() { }

// ���������촦��
private void create() { load_tips(); }

// ��������ȡ��ʾ����
private void load_tips()
{
        string text, *line, content;
        int level, i, size;

        // ������ʾ����
        text = read_file( TIPS );
        text = replace_string(text, " HIR ", HIR);
        text = replace_string(text, "HIR", HIR);
        text = replace_string(text, " HIY ", HIY);
        text = replace_string(text, "HIY", HIY);
        line = explode(text, "\n");

        // ������ʾ����
        for( i = 0, size = sizeof(line); i < size; i ++ ) 
        {
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( line[i][<1] <= ' ' ) line[i] = line[i][0..<2];    // UNIX ��ʽ
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( !sscanf( line[i], "%d:%s", level, content ) ) 
                {
                        log_file( ERROR, sprintf( "����: " TIPS " �� %d ����ʾ�����\n", i + 1 ) );
                        continue;
                }
                switch( level ) 
                {
               case 1 : TipsA += ({ content });  break;
               case 2 : TipsB += ({ content });  break;
               case 3 : TipsC += ({ content });  break;
             case 900 : Battle += ({ content });  break;
                }
        }
        sizeof_TipsA = sizeof(TipsA);
        sizeof_TipsB = sizeof(TipsB);
        sizeof_TipsC = sizeof(TipsC);
        sizeof_Battle = sizeof(Battle);
}

// ��������ȡ������ʾ
string *get_tips_a() { return copy(TipsA); }

// ��������ȡ�ͼ���ʾ
string *get_tips_b() { return copy(TipsB); }

// ��������ȡ������ʾ
string *get_tips_c() { return copy(TipsC); }

// ��������ȡս����ʾ
string *get_battle() { return copy(Battle); }

// ��������ʾ�����λ
private void random_tips_a()
{
        string text;
        int a, b, i;

        for( i = 0; i < sizeof_TipsA; i ++ )
        {
                a = random(sizeof_TipsA);  b = random(sizeof_TipsA);
                text = TipsA[a];  TipsA[a] = TipsA[b];  TipsA[b] = text;
        }
}

// ��������ʾ�����λ
private void random_tips_b()
{
        string text;
        int a, b, i;

        for( i = 0; i < sizeof_TipsB; i ++ )
        {
                a = random(sizeof_TipsB);  b = random(sizeof_TipsB);
                text = TipsB[a];  TipsB[a] = TipsB[b];  TipsB[b] = text;
        }
}

// ��������ʾ�����λ
private void random_tips_c()
{
        string text;
        int a, b, i;

        for( i = 0; i < sizeof_TipsC; i ++ )
        {
                a = random(sizeof_TipsC);  b = random(sizeof_TipsC);
                text = TipsC[a];  TipsC[a] = TipsC[b];  TipsC[b] = text;
        }
}

// ��������ʾ�����λ
private void random_battle()
{
        string text;
        int a, b, i;

        for( i = 0; i < sizeof_Battle; i ++ )
        {
                a = random(sizeof_Battle);  b = random(sizeof_Battle);
                text = Battle[a];  Battle[a] = Battle[b];  Battle[b] = text;
        }
}

// ��������ʾ��ʾ�����
void send_tips_to_user()
{
        object *user;

        user = USER_D->get_level_a_user();
        if( sizeof(user) && sizeof_TipsA )
        {
                if( TipsCount % sizeof_TipsA == 0 ) random_tips_a();
                send_user( user, "%c%s", 0x22, TipsA[ TipsCount % sizeof_TipsA ] );
        }

        user = USER_D->get_level_b_user();
        if( sizeof(user) && sizeof_TipsB ) 
        {
                if( TipsCount % sizeof_TipsB == 0 ) random_tips_b();
                send_user( user, "%c%s", 0x22, TipsB[ TipsCount % sizeof_TipsB ] );
        }

        user = USER_D->get_level_c_user();
        if( sizeof(user) && sizeof_TipsC ) 
        {
                if( TipsCount % sizeof_TipsC == 0 ) random_tips_c();
                send_user( user, "%c%s", 0x22, TipsC[ TipsCount % sizeof_TipsC ] );
        }

        user = USER_D->get_battle_user();
        if( sizeof(user) && sizeof_Battle ) 
        {
                if( TipsCount % sizeof_Battle == 0 ) random_battle();
                send_user( user, "%c%s", 0x22, Battle[ TipsCount % sizeof_Battle ] );
        }

        TipsCount ++;
}
