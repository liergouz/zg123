
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1271; }

// ���������촦��
void create()
{
        set_name("ս���");
        set_picid_1(6580);
        set_picid_2(6580);

        set_level(50);
        set_value(4500);
        set_max_lasting(12899);
        set("ap", 0);
        set("dp", 90);
        set("cp", 0);
        set("pp", 30);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ս���";
}
