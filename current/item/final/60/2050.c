
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 1266; }

// ���������촦��
void create()
{
        set_name("��Х��װ");
        set_picid_1(6023);
        set_picid_2(6023);

        set_level(50);
        set_value(4000);
        set_max_lasting(9899);
        set("ap", 0);
        set("dp", 121);
        set("cp", 0);
        set("pp", 80);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��Х��װ";
}
