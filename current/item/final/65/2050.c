
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 1276; }

// ���������촦��
void create()
{
        set_name("��Хͷ��");
        set_picid_1(6500);
        set_picid_2(6500);

        set_level(50);
        set_value(4500);
        set_max_lasting(12899);
        set("ap", 0);
        set("dp", 86);
        set("cp", 0);
        set("pp", 42);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��Хͷ��";
}
