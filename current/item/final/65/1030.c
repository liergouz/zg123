
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1229; }

// ���������촦��
void create()
{
        set_name("˿���");
        set_picid_1(6574);
        set_picid_2(6574);

        set_level(30);
        set_value(3000);
        set_max_lasting(9099);
        set("ap", 0);
        set("dp", 55);
        set("cp", 0);
        set("pp", 25);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "˿���";
}
