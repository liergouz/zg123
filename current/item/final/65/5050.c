
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 5; }

// ��������Ʒ���
int get_fin_type() { return 1273; }

// ���������촦��
void create()
{
        set_name("��ɹ�");
        set_picid_1(6578);
        set_picid_2(6578);

        set_level(50);
        set_value(4500);
        set_max_lasting(12899);
        set("ap", 0);
        set("dp", 43);
        set("cp", 0);
        set("pp", 67);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ɹ�";
}
