
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 2203; }

// ���������촦��
void create()
{
        set_name("������װ");
        set_picid_1(6013);
        set_picid_2(6013);

        set_level(85);
        set_value(9500);
        set_max_lasting(23899);
        set("ap", 0);
        set("dp", 201);
        set("cp", 0);
        set("pp", 122);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������װ";
}
