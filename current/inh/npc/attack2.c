
private static object Enemy4;           // ������������
private static int AttackTime;          // ��������ʱ��

private static int FightTime;           // ���﹥��ʱ�䣺�ٻ��޼�¼����ʱ�䣬���� 110 ������ͷ��������

private static int MaxDamage = 0;       // �ܵ�����˺�
private static object MainEnemy = 0;    // ����Ҫ�ĵ��ˣ�NPC ���ȵĹ�������

// -------------------------------------------------------------

// ��������ȡ������������
object get_enemy_4() { return Enemy4; }

// ���������ó�����������
object set_enemy_4( object who ) { return Enemy4 = who; }

// ��������ȡ��������ʱ��
int get_attack_time() { return AttackTime; }

// ���������ó�������ʱ��
int set_attack_time( int time ) { return AttackTime = time; }

// ��������ȡ���﹥��ʱ��
int get_fight_time() { return FightTime; }

// ���������ó��﹥��ʱ��
int set_fight_time( int time ) { return FightTime = time; }

// -------------------------------------------------------------

// ��������ȡ�ܵ�����˺�
int get_max_damage() { return MaxDamage; }

// �����������ܵ�����˺�
int set_max_damage( int point ) { return MaxDamage = point; }

// ��������ȡ����Ҫ�ĵ���
object get_main_enemy() { return MainEnemy; }

// ��������������Ҫ�ĵ���
object set_main_enemy( object who ) { return MainEnemy = who; }

// ��������ʼ�������˺�
void init_enemy_damage( object who, int point )
{
        MainEnemy = who;  MaxDamage = point;
}
