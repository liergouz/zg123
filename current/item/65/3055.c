
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("�ɱ���");
        set_picid_1(6538);
        set_picid_2(6538);

        set_level(55);
        set_value(13700);
        set_max_lasting(9699);
        set("dp", 74);
        set("pp", 31);

        setup();

        set_gender(1);
        set_head_code(44);
}

// ��������ȡ����
string get_desc()
{
        return "�ɱ���";
}
