
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("�׻�ͷ��");
        set_picid_1(6603);
        set_picid_2(6603);

        set_level(35);
        set_value(9700);
        set_max_lasting(5799);
        set("dp", 26);
        set("pp", 42);

        setup();

        set_gender(2);
        set_head_code(52);
}

// ��������ȡ����
string get_desc()
{
        return "�׻�ͷ��";
}
