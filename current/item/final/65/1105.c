
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 2250; }

// ���������촦��
void create()
{
        set_name("����֮��");
        set_picid_1(6582);
        set_picid_2(6582);

        set_level(105);
        set_value(11000);
        set_max_lasting(26899);
        set("ap", 0);
        set("dp", 205);
        set("cp", 0);
        set("pp", 64);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����֮��";
}
